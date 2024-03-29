// NetworkGameServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include "pch.h"
#include"GameScene.h"
#include"Planet.h"
#include<mutex>
#include"HPItem.h"
#include"ChangeItem.h"
#include"Missile.h"

mutex m;
#define SPEED 3
//Func
DWORD CreatePlayerThread(LPVOID arg);

int recvn(SOCKET s, char *buf, int len, int flags);
void err_quit(const char *msg);
void err_display(const char *msg);
void KeyBoardCalculation();
void Init();
//

All_Data AllData;
Client_Packet ClientPacket;
CMissile* missile[MISSILE_MAX];

void err_quit(const char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
		MessageBox(NULL, (LPCTSTR)lpMsgBuf, (LPCWSTR)msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}

// 소켓 함수 오류 출력
void err_display(const char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	printf("[%s] %s", msg, (char *)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

int recvn(SOCKET s, char *buf, int len, int flags)
{
	int retval;
	char *ptr = buf;
	int  left = len;

	while (left > 0)
	{
		retval = recv(s, ptr, left, flags);

		if (retval == SOCKET_ERROR)
			return SOCKET_ERROR;

		else if (retval == 0)
			break;

		left -= retval;
		ptr += retval;
	}
	return (len - left);
}

void Init()
{
	for (int i = 0; i < PLAYER_MAX; ++i)
	{
		AllData.ClientPacket[i].PlayerMaxHp = 100;
		AllData.ClientPacket[i].PlayerHp = 100;
		AllData.ClientPacket[static_cast<int>(AllData.ClientPacket->PlayerID)].Pos.x = (CLIENT_WIDTH - 100) * static_cast<int>(AllData.ClientPacket->PlayerID);
		AllData.ClientPacket[static_cast<int>(AllData.ClientPacket->PlayerID)].Pos.y = CLIENT_HEIGHT / 2;

	}
	CPlanet::GetInstance()->Init();
	CHpItem::GetInstance()->Init();
	CChangeItem::GetInstance()->Init();
	CMissile::GetInstance()->Init();
}


int main(int argc, char* argv[])
{
	int retval;

	// 윈속 초기화
	WSADATA WsaData;
	if (WSAStartup(MAKEWORD(2, 2), &WsaData) != 0)
	{
		return 1;
	}

	// socket()
	SOCKET ListenSock = socket(AF_INET, SOCK_STREAM, 0);
	if (ListenSock == INVALID_SOCKET)
		err_quit("socket()");

	// bind()
	SOCKADDR_IN ServerAddr;
	ZeroMemory(&ServerAddr, sizeof(ServerAddr));
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	ServerAddr.sin_port = htons(SERVERPORT);
	retval = ::bind(ListenSock, (SOCKADDR *)&ServerAddr, sizeof(ServerAddr));
	if (retval == SOCKET_ERROR)
	{
		err_quit("bind()");
	}

	// listen()
	retval = listen(ListenSock, SOMAXCONN);
	if (retval == SOCKET_ERROR)
	{
		err_quit("listen()");
	}
	// 데이터 통신에 사용할 변수
	SOCKET client_sock;
	SOCKADDR_IN clientaddr;
	int addrlen;
	//Thread
	HANDLE hThread[2];
	//


	while (true)
	{
		// accept()
		addrlen = sizeof(clientaddr);
		client_sock = accept(ListenSock, (SOCKADDR *)&clientaddr, &addrlen);
		printf("connect()");
		if (client_sock == INVALID_SOCKET)
		{
			err_display("accept()");
			break;
		}

		// 접속한 클라이언트 정보 출력
		printf("\n[TCP 서버] 클라이언트 접속: IP 주소=%s, 포트 번호=%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

		int ID = -1;

		for (int i = 0; i < PLAYER_MAX; ++i)
		{
			if (AllData.ClientPacket[i].connect == false)
			{
				ID = i;
				AllData.ClientPacket[i].connect = true;
				break;
			}
		}

		if (ID == 0)
		{
			AllData.ClientPacket[ID].BitMapID = "Player1R";
		}
		else if (ID == 1)
		{
			AllData.ClientPacket[ID].BitMapID = "Player2L";
		}
		
		AllData.ClientPacket->PlayerID = static_cast<ENUM_CLIENT>(ID);
		AllData.ClientPacket->GameStart = false;
		
		send(client_sock, (char*)&AllData, sizeof(All_Data), 0);

		cout << endl << endl;
		cout << "ID : " << ID << endl << endl << endl;

		if (0 == ID)
			hThread[ID] = CreateThread(NULL, 0, CreatePlayerThread, (LPVOID)client_sock, 0, NULL);

		else
			hThread[ID] = CreateThread(NULL, 0, CreatePlayerThread, (LPVOID)client_sock, 0, NULL);


		if (ID == PLAYER_MAX-1)
		{
			AllData.ClientPacket->GameStart = true;
			Init();
		}
	}
	closesocket(ListenSock);
	WSACleanup();
}

//클라가 주고받는시간만큼 서버도 주고받기
//클라랑 동기화
auto start = std::chrono::high_resolution_clock::now();

float preTime = timeGetTime() *0.001f;
DWORD CreatePlayerThread(LPVOID arg)
{
	SOCKET ClientSock = (SOCKET)arg;

	while (true)
	{
		if (timeGetTime() * 0.001f - preTime > 0.01f)
		{
			preTime = timeGetTime() * 0.001f;
			//받은 클라 데이터
			recvn(ClientSock, (char*)&ClientPacket, sizeof(ClientPacket), 0);
		
			KeyBoardCalculation();
//			std::chrono::duration<double>time = std::chrono::high_resolution_clock::now() - start;
			CGameScene::GetInstance()->Update(preTime);
//			CMissile::GetInstance()->Update(preTime);
//			start = std::chrono::high_resolution_clock::now();
			send(ClientSock, (char*)&AllData, sizeof(All_Data), 0);
		}
	}
	return 0;
}

//플레이어 움직임 처리 함수
void KeyBoardCalculation()
{
	m.lock();
	int ClientNumber{ 0 };
	ClientNumber = static_cast<int>(ClientPacket.PlayerID);


	//플레이어 아이디 0번
	if (ClientNumber == 0)
	{
		
		if (ClientPacket.enumDir == ENUM_DIRECTION::RIGHT)
		{
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].Pos.x += SPEED;		
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].BitMapID = "Player1R";		
			
		}

		else if (ClientPacket.enumDir == ENUM_DIRECTION::LEFT)
		{
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].Pos.x -= SPEED;
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].BitMapID = "Player1L";
			
		}

		else if (ClientPacket.enumDir == ENUM_DIRECTION::DOWN)
		{
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].Pos.y += SPEED;
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].BitMapID = "Player1D";
			
		}

		else if (ClientPacket.enumDir == ENUM_DIRECTION::UP)
		{
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].Pos.y -= SPEED;
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].BitMapID = "Player1U";
			
		}
		

	}
	//플레이어 아이디 1번
	else if (ClientNumber == 1)
	{
		
		if (ENUM_DIRECTION::RIGHT == ClientPacket.enumDir)
		{
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].Pos.x += SPEED;
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].BitMapID = "Player2R";
			
		}

		else if (ENUM_DIRECTION::LEFT == ClientPacket.enumDir)
		{
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].Pos.x -= SPEED;
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].BitMapID = "Player2L";
			
		}
		else if (ENUM_DIRECTION::DOWN == ClientPacket.enumDir)
		{
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].Pos.y += SPEED;
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].BitMapID = "Player2D";
			
		}

		else if (ENUM_DIRECTION::UP == ClientPacket.enumDir)
		{
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].Pos.y -= SPEED;
			AllData.ClientPacket[static_cast<int>(ClientPacket.PlayerID)].BitMapID = "Player2U";
			
		}

	}

	m.unlock();
}