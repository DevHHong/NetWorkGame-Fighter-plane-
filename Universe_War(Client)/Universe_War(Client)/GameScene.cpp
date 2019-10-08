#include "stdafx.h"
#include "GameScene.h"
#include"ClientNetwork.h"
#include "Player.h"
#include "Planet.h"
#include "Item.h"
#include "HpItem.h"
#include "ChangeItem.h"
#include "Missile.h"


//extern====================================
All_Data AllData;




CGameScene::CGameScene()
{
}

CGameScene::~CGameScene()
{
	Release();
}

void CGameScene::Create(HWND hWnd)
{
	CScene::CreateBitMapPath(hWnd);
	ClientNetwork::GetInstance()->Init();

//	CMissile::GetInstance()->Init();
	mpPlayer = new CPlayer();
	
}

void CGameScene::Render(HDC hdc)
{
	//클라는 렌더링만

	mBackGround.Render(hdc);
	if (mpPlayer)
	{
		mpPlayer->Render(hdc);		
	}
	if (AllData.ClientPacket[0].PlayerHp > 0 && AllData.ClientPacket[1].PlayerHp > 0)
	{
		CPlanet::GetInstance()->Render(hdc);
		CHpItem::GetInstance()->Render(hdc);
		CChangeItem::GetInstance()->Render(hdc);
//		CMissile::GetInstance()->Render(hdc);
	}
}
	
void CGameScene::Update(const float ftime)
{
	//클라임 업데이트 필요 x	
	if (mpPlayer)
	{
		mpPlayer->Update(ftime);	
	}		
	//클라 데이터 send
	send(ClientNetwork::GetInstance()->sock, (char*)& ClientPacket, sizeof(Client_Packet), 0);

	//모든데이터 recv 
	ClientNetwork::GetInstance()->recvn(ClientNetwork::GetInstance()->sock, (char*)&AllData, sizeof(All_Data), 0);
}

void CGameScene::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
}

void CGameScene::Release()
{
	if (mpPlayer)
		delete mpPlayer;
}


