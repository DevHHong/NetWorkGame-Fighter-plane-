#include "stdafx.h"
#include "ClientNetwork.h"


//SingleTone
ClientNetwork* ClientNetwork::Instance = NULL;

ClientNetwork::ClientNetwork()
{
}
ClientNetwork::~ClientNetwork()
{
}
void ClientNetwork::Init()
{
	int retval;

	WSADATA	WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);

	// socket()
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
		err_quit("socket()");

	//connect()
	SOCKADDR_IN ServerAddr;
	ZeroMemory(&ServerAddr, sizeof(SOCKADDR_IN));
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(SERVERPORT);
	ServerAddr.sin_addr.s_addr = inet_addr(IP);

	retval = connect(sock, (SOCKADDR *)&ServerAddr, sizeof(ServerAddr));
	if (retval == SOCKET_ERROR)
		err_quit("connect()");

	recvn(sock, (char*)&AllData, sizeof(All_Data), 0);


	//네트워크 아이디 플레이어 패킷 전송받은 아이디로 맞추고
	ClientID = AllData.ClientPacket->PlayerID;
	cout << "ClinetNetWork클래스에서 recvn()받았음" << endl;
}

void ClientNetwork::Render(HDC hdc)
{
	

}

int ClientNetwork::recvn(SOCKET s, char* buf, int len, int flags)
{
	int received;
	char *ptr = buf;
	int left = len;

	while (left > 0)
	{
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;
		else if (received == 0)
			break;
		left -= received;
		ptr += received;
	}
	return (len - left);
}

void ClientNetwork::err_display(const char * msg)
{
	LPVOID lpMsgBuf;
	FormatMessage
	(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL
	);
	printf("[%s] %s", msg, (char *)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

void ClientNetwork::err_quit(const char * msg)
{
	LPVOID lpMsgBuf;
	FormatMessage
	(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL
	);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, (LPCWSTR)msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}
