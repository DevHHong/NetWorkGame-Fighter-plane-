#include "stdafx.h"
#include "Player.h"
#include"ClientNetwork.h"

Client_Packet ClientPacket;


CPlayer::CPlayer()
{		
	if (AllData.ClientPacket->PlayerID == ENUM_CLIENT::NUM1)
	{
		ClientPacket.enumDir = ENUM_DIRECTION::RIGHT;

		ClientPacket.State = ENUM_OBJSTATE::LIVE;
	}
	if (AllData.ClientPacket->PlayerID == ENUM_CLIENT::NUM2)
	{
		ClientPacket.enumDir = ENUM_DIRECTION::LEFT;

		ClientPacket.State = ENUM_OBJSTATE::LIVE;
	}

	// 아이템
	for (BitInfo& d : ItemUI)
		d = BitInfo("ItemUI1", 64, 64, RGB(255, 255, 255));

	for (ENUM_ITEMTYPE& d : itemType)
		d = ENUM_ITEMTYPE::NONE;
	

	//네트워크에서 한번 받은 아이디들 맞춰주고
	ClientPacket.PlayerID = ClientNetwork::GetInstance()->ClientID;
	
	ClientPacket.BitMapsizeX = 64;
	ClientPacket.BitMapsizeY = 64;
	ClientPacket.BitMapcolor = RGB(255, 255, 255);

	ClientPacket.ShootMissile = false;
	ClientPacket.GameStart = false;
	ClientPacket.UseHpChangeItem = false;
	ClientPacket.UseHpGainItem = false;
	ClientPacket.connect = false;	
}

CPlayer::~CPlayer()
{
}

void CPlayer::Create(HWND hWnd)
{
}

void CPlayer::Render(HDC hdc)
{
	
	if (AllData.ClientPacket->GameStart == false)
		{
			TextOutA(hdc, 360,7, "Lobby Scene", 11);
			return;
		}
	else
		TextOutA(hdc, 360,7, "Game Scene", 10);


	if (AllData.ClientPacket[0].PlayerHp < 0)
	{
		TextOutA(hdc, 360, 7, "초록비행기 승리", 15);
		return;
	}
	if (AllData.ClientPacket[1].PlayerHp < 0)
	{
		TextOutA(hdc, 360, 7, "하얀비행기 승리", 15);
		return;
	}
	
	for (int i = 0; i < PLAYER_MAX; ++i)
	{
		if (AllData.ClientPacket[i].connect == true)
		{
			TransparentBlt
			(
				hdc,
				AllData.ClientPacket[i].Pos.x,
				AllData.ClientPacket[i].Pos.y,
				ClientPacket.BitMapsizeX,
				ClientPacket.BitMapsizeY,
				(*m_pMapBmp)[AllData.ClientPacket[i].BitMapID]->GetMemDC(),
				0,
				0,
				ClientPacket.BitMapsizeX,
				ClientPacket.BitMapsizeY,
				RGB(255, 255, 255)
			);
			
		}		
	}				
	
	HpRender(hdc);
}

void CPlayer::Update(const float ftime)
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if (ClientPacket.PlayerID == ENUM_CLIENT::NUM1)
		{
			ClientPacket.ShootMissile = true;
		}
		else if (ClientPacket.PlayerID == ENUM_CLIENT::NUM2)
		{
			ClientPacket.ShootMissile = true;
		}

	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{	
		if (ClientPacket.PlayerID == ENUM_CLIENT::NUM1)
		{
			ClientPacket.enumDir = ENUM_DIRECTION::LEFT;
		}
		else if (ClientPacket.PlayerID == ENUM_CLIENT::NUM2)
		{
			ClientPacket.enumDir = ENUM_DIRECTION::LEFT;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (ClientPacket.PlayerID == ENUM_CLIENT::NUM1)
		{
			ClientPacket.enumDir = ENUM_DIRECTION::RIGHT;
		}
		else if (ClientPacket.PlayerID == ENUM_CLIENT::NUM2)
		{
			ClientPacket.enumDir = ENUM_DIRECTION::RIGHT;
		}
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if (ClientPacket.PlayerID == ENUM_CLIENT::NUM1)
		{
			ClientPacket.enumDir = ENUM_DIRECTION::UP;
		}
		else if (ClientPacket.PlayerID == ENUM_CLIENT::NUM2)
		{
			ClientPacket.enumDir = ENUM_DIRECTION::UP;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if (ClientPacket.PlayerID == ENUM_CLIENT::NUM1)
		{
			ClientPacket.enumDir = ENUM_DIRECTION::DOWN;
		}
		else if (ClientPacket.PlayerID == ENUM_CLIENT::NUM2)
		{
			ClientPacket.enumDir = ENUM_DIRECTION::DOWN;
		}
	}

	//printf("Player ID: %d\n", static_cast<int>(ClientPacket.PlayerID));
	//printf("Pos.x : %f\n", AllData.ClientPacket->Pos.x);
	//cout << AllData.ClientPacket->PlayerHp << ", " << AllData.ClientPacket->PlayerMaxHp << endl;

	//printf("ID : %d\n", static_cast<int>(ClientNetwork::GetInstance()->ClientID));
	
}

void CPlayer::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
}

void CPlayer::Release()
{

}

void CPlayer::HpRender(HDC hdc)
{
	for (int i = 0; i < PLAYER_MAX; ++i)
	{
		if (AllData.ClientPacket[i].connect == true)
		{
			HBRUSH m_br = CreateSolidBrush(RGB(i*255, 0, 255-(i*255)));
			HBITMAP Ahbmp = CreateCompatibleBitmap(hdc, 100, 100);
			HDC Ahdc = CreateCompatibleDC(hdc);
			HBITMAP Aoldbmp = (HBITMAP)SelectObject(Ahdc, Ahbmp);
			auto oldbr = SelectObject(Ahdc, m_br);
			Rectangle(Ahdc, 0, 0, 100, 100);
			SelectObject(Ahdc, oldbr);
			BLENDFUNCTION bf;

			bf.BlendOp = AC_SRC_OVER;
			bf.BlendFlags = 0;
			bf.AlphaFormat = 0;
			bf.SourceConstantAlpha = 150;

			float hpRate = AllData.ClientPacket[i].PlayerHp / AllData.ClientPacket[i].PlayerMaxHp;			// 현재 hp 비율
			float start = 0;					// 시작 점
			float end = 200;						// 끝점
			int curHp = int(start * (1.f - hpRate) + end * hpRate);		// 선형보간법 공식

			AlphaBlend(hdc, i*599, 25, curHp, 30, Ahdc, 0, 0, 100, 100, bf);
			SelectObject(Ahdc, Aoldbmp);
			DeleteObject(m_br);
			DeleteObject(Ahbmp);
			DeleteDC(Ahdc);

			HPEN hPen = CreatePen(PS_SOLID, 2, RGB(i*200, 0, 200-(i*200)));
			HPEN oldPen = (HPEN)SelectObject(hdc, hPen);
			auto old = SelectObject(hdc, GetStockObject(NULL_BRUSH));
			Rectangle(hdc, i* 601, 25, i*600+200, 55);
			SelectObject(hdc, old);
			SelectObject(hdc, oldPen);
			DeleteObject(hPen);			
		}
	}	
}

void CPlayer::ItemRender(HDC hdc)
{
	
}
