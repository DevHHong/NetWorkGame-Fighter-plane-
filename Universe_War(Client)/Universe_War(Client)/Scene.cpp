#include "stdafx.h"
#include "Scene.h"

#include "BitMap.h"
#include "GameObj.h"
CScene::CScene()
{
}


CScene::~CScene()
{
}

void CScene::CreateBitMapPath(HWND hWnd)
{
	m_MapBmp["BackGround"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/BackGround.bmp");
	m_MapBmp["Planet"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/planet.bmp");
	m_MapBmp["HpItem"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/HpItem.bmp");
	m_MapBmp["ChangeItem"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/ChangeItem.bmp");
	m_MapBmp["Missile"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/missile.bmp");

	// ItemUI
	m_MapBmp["ItemUI1"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/ItemUI1.bmp");
	m_MapBmp["ItemUI2"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/ItemUI2.bmp");
	m_MapBmp["ItemUI3"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/ItemUI3.bmp");

	// Player 1
	m_MapBmp["Player1D"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/Player1_down.bmp");
	m_MapBmp["Player1L"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/Player1_left.bmp");
	m_MapBmp["Player1R"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/Player1_right.bmp");
	m_MapBmp["Player1U"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/Player1_up.bmp");

	// Player 2
	m_MapBmp["Player2D"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/Player2_down.bmp");
	m_MapBmp["Player2L"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/Player2_left.bmp");
	m_MapBmp["Player2R"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/Player2_right.bmp");
	m_MapBmp["Player2U"] = (new CBitMap)->LoadBmp(hWnd, (PTCHAR)L"../Texture/Player2_up.bmp");

	CGameObj::SetBmp(&m_MapBmp);
}
