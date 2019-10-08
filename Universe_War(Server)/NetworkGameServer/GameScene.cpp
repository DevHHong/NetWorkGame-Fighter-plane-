#include "pch.h"
#include "GameScene.h"
//#include"ClientNetwork.h"
#include "Player.h"
#include "Planet.h"
#include "Item.h"
#include "HpItem.h"
#include "ChangeItem.h"
#include "Missile.h"

//SingleTone
CGameScene* CGameScene::Instance = NULL;

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
}

void CGameScene::Render(HDC hdc)
{
	//서버임. 렌더링필요 x
}

void CGameScene::Release()
{
	
}

void CGameScene::Update(const float ftime)
{
	CPlanet::GetInstance()->Update(ftime);
	CHpItem::GetInstance()->Update(ftime);
	CChangeItem::GetInstance()->Update(ftime);

}

void CGameScene::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
}


