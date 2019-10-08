#include "pch.h"
#include "Player.h"


//SingleTone
CPlayer* CPlayer::Instance = NULL;

CPlayer::CPlayer()
{
	//Player1
	mBitInfo = BitInfo("Player1U", 64, 64, RGB(255, 255, 255));

	//Player2
//	mBitInfo = BitInfo("Player2U", 64, 64, RGB(255, 255, 255));
	pos.x = CLIENT_WIDTH / 2, pos.y = CLIENT_HEIGHT / 2;

	Speed = 150.f;
	dir = Point(0, 0);
	state = ENUM_OBJSTATE::LIVE;
	//Player1 part
	client = ENUM_CLIENT::NUM1;
	//
	if (client == ENUM_CLIENT::NUM1)
		mBitInfo.ID = "Player1U";
	else if (client == ENUM_CLIENT::NUM2)
		mBitInfo.ID = "Player2U";
	enumDir = ENUM_DIRECTION::DOWN;
	Hp = MaxHp = 100;
	state = ENUM_OBJSTATE::LIVE;

	// 아이템
	for (BitInfo& d : ItemUI)
		d = BitInfo("ItemUI1", 64, 64, RGB(255, 255, 255));

	for (ENUM_ITEMTYPE& d : itemType)
		d = ENUM_ITEMTYPE::NONE;


	////NetWork
	ClientPacket.Pos.x = pos.x;
	ClientPacket.Pos.y = pos.y;
	ClientPacket.PlayerHp = Hp;
	ClientPacket.PlayerMaxHp = Hp;
	ClientPacket.PlayerID = client;
	ClientPacket.GameStart = false;
	ClientPacket.State = state;
	ClientPacket.UseHpChangeItem = false;
	ClientPacket.UseHpGainItem = false;
	ClientPacket.enumDir = enumDir;
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

}
float CPlayer::getHp()
{
	for (int i = 0; i = PLAYER_MAX; ++i)
	{
		if (client == ENUM_CLIENT::NUM1)
		{
			return AllData.ClientPacket[static_cast<int>(client)].PlayerHp;
		}
		else if (client == ENUM_CLIENT::NUM2)
		{
			return AllData.ClientPacket[static_cast<int>(client)].PlayerHp;
		}
		
	}
}
Point CPlayer::getPos()
{
	for (int i = 0; i = PLAYER_MAX; ++i)
	{
		if (client == ENUM_CLIENT::NUM1)
		{
			return AllData.ClientPacket[static_cast<int>(client)].Pos;
		}
		else if (client == ENUM_CLIENT::NUM2)
		{
			return AllData.ClientPacket[static_cast<int>(client)].Pos;
		}
	}
}
float CPlayer::getRange()
{
	for (int i = 0; i = PLAYER_MAX; ++i)
	{
		if (client == ENUM_CLIENT::NUM1)
		{
			return AllData.ClientPacket[static_cast<int>(client)].BitMapsizeX / 2.f;
		}
		else if (client == ENUM_CLIENT::NUM2)
		{
			return AllData.ClientPacket[static_cast<int>(client)].BitMapsizeX / 2.f;
		}
	}
}
void CPlayer::setState(ENUM_OBJSTATE s)
{
	for (int i = 0; i = PLAYER_MAX; ++i)
	{
		if (client == ENUM_CLIENT::NUM1)
		{
			AllData.ClientPacket[static_cast<int>(client)].State = s;
		}
		else if (client == ENUM_CLIENT::NUM2)
		{
			AllData.ClientPacket[static_cast<int>(client)].State = s;
		}
	}
}
void CPlayer::setDamage(float d)
{

	if (client == ENUM_CLIENT::NUM1)
	{
		AllData.ClientPacket[static_cast<int>(client)].PlayerHp -= d;
	}
	else if (client == ENUM_CLIENT::NUM2)
	{
		AllData.ClientPacket[static_cast<int>(client)].PlayerHp -= d;
	}
	
}
void CPlayer::Update(const float ftime)
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{		
		if (client == ENUM_CLIENT::NUM1)
		{
			//mBitInfo.ID = "Player1L";
			enumDir = ENUM_DIRECTION::LEFT;
			AllData.ClientPacket[static_cast<int>(client)].enumDir = enumDir;
			AllData.ClientPacket[static_cast<int>(client)].BitMapID = "Player1L";
			
		}
		else if (client == ENUM_CLIENT::NUM2)
		{
			//mBitInfo.ID = "Player2L";
			enumDir = ENUM_DIRECTION::LEFT;
			AllData.ClientPacket[static_cast<int>(client)].enumDir = enumDir;
			AllData.ClientPacket[static_cast<int>(client)].BitMapID = "Player2L";
			
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		
		if (client == ENUM_CLIENT::NUM1)
		{
			//mBitInfo.ID = "Player1R";
			enumDir = ENUM_DIRECTION::RIGHT;
			AllData.ClientPacket[static_cast<int>(client)].enumDir = enumDir;
			AllData.ClientPacket[static_cast<int>(client)].BitMapID = "Player1R";
		}

		else if (client == ENUM_CLIENT::NUM2)
		{
			//mBitInfo.ID = "Player2R";
			enumDir = ENUM_DIRECTION::RIGHT;
			AllData.ClientPacket[static_cast<int>(client)].enumDir = enumDir;
			AllData.ClientPacket[static_cast<int>(client)].BitMapID = "Player2R";
		}
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		

		if (client == ENUM_CLIENT::NUM1)
		{
			//mBitInfo.ID = "Player1U";
			enumDir = ENUM_DIRECTION::UP;
			AllData.ClientPacket[static_cast<int>(client)].enumDir = enumDir;
			AllData.ClientPacket[static_cast<int>(client)].BitMapID = "Player1U";
		}

		else if (client == ENUM_CLIENT::NUM2)
		{
			//mBitInfo.ID = "Player2U";
			enumDir = ENUM_DIRECTION::UP;
			AllData.ClientPacket[static_cast<int>(client)].enumDir = enumDir;
			AllData.ClientPacket[static_cast<int>(client)].BitMapID = "Player2U";
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{

		if (client == ENUM_CLIENT::NUM1)
		{
			//mBitInfo.ID = "Player1D";
			enumDir = ENUM_DIRECTION::DOWN;
			AllData.ClientPacket[static_cast<int>(client)].enumDir = enumDir;
			AllData.ClientPacket[static_cast<int>(client)].BitMapID = "Player1D";
		}

		else if (client == ENUM_CLIENT::NUM2)
		{
			//mBitInfo.ID = "Player2D";
			enumDir = ENUM_DIRECTION::DOWN;
			AllData.ClientPacket[static_cast<int>(client)].enumDir = enumDir;
			AllData.ClientPacket[static_cast<int>(client)].BitMapID = "Player2D";
		}
	}
	if (Hp <= 0)
	{
		state = ENUM_OBJSTATE::DIE;
		//NetWork	
		ClientPacket.State = state;
		return;
	}

}

void CPlayer::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_KEYDOWN)
	{
		if (wParam == VK_SHIFT && itemCnt > 0)
		{
			--itemCnt;
			if (itemType[itemCnt] == ENUM_ITEMTYPE::ITEM1)
			{
				Hp += 30;
				if (Hp > MaxHp)
				{
					Hp = MaxHp;
				}
				//NetWork

				ClientPacket.PlayerHp = Hp;

			}
			else if (itemType[itemCnt] == ENUM_ITEMTYPE::ITEM2)
			{

				/* 서버 연결후 체력 체인지로 만들 예정.*/

			}
			itemType[itemCnt] = ENUM_ITEMTYPE::NONE;
		}
		else if (message == VK_RETURN)
		{

		}
	}
	else if (message == WM_KEYUP)
	{
		dir = Point{ 0,0 };
	}

}

void CPlayer::Release()
{

}

void CPlayer::HpRender(HDC hdc)
{
	HBRUSH m_br = CreateSolidBrush(RGB(255, 0, 0));
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

	float hpRate = Hp / MaxHp;			// 현재 hp 비율
	float start = 0;					// 시작 점
	float end = 200;						// 끝점
	int curHp = int(start * (1.f - hpRate) + end * hpRate);		// 선형보간법 공식

	AlphaBlend(hdc, 0, 25, curHp, 30, Ahdc, 0, 0, 100, 100, bf);
	SelectObject(Ahdc, Aoldbmp);
	DeleteObject(m_br);
	DeleteObject(Ahbmp);
	DeleteDC(Ahdc);

	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(200, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, hPen);
	auto old = SelectObject(hdc, GetStockObject(NULL_BRUSH));
	Rectangle(hdc, 0, 25, 200, 55);
	SelectObject(hdc, old);
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}

void CPlayer::ItemRender(HDC hdc)
{
	for (int i = 0; i < 2; ++i)
	{
		if (itemType[i] == ENUM_ITEMTYPE::NONE)
		{
			ItemUI[i].ID = "ItemUI1";
		}
		else if (itemType[i] == ENUM_ITEMTYPE::ITEM1)
		{
			ItemUI[i].ID = "ItemUI2";
		}
		else if (itemType[i] == ENUM_ITEMTYPE::ITEM2)
		{
			ItemUI[i].ID = "ItemUI3";
		}
		TransparentBlt(hdc, 10 + (i*(ItemUI[i].sizeX + 10)), 60,
			ItemUI[i].sizeX, ItemUI[i].sizeY, (*m_pMapBmp)[ItemUI[i].ID]->GetMemDC(),
			0, 0, ItemUI[i].sizeX, ItemUI[i].sizeY, ItemUI[i].color);
	}
}
