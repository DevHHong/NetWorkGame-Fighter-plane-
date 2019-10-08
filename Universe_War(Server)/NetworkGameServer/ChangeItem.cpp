#include "pch.h"
#include "ChangeItem.h"

//SingleTone
CChangeItem* CChangeItem::Instance = NULL;

CChangeItem::CChangeItem()
{

}
void CChangeItem::Init()
{
	for (int i = 0; i < CHANGEITEM_MAX; ++i)
	{
		AllData.ChangeItemPacket[i].BitMapID = "ChangeItem";
		AllData.ChangeItemPacket[i].BitMapcolor = RGB(255, 255, 255);
		AllData.ChangeItemPacket[i].BitMapsizeX = 32;
		AllData.ChangeItemPacket[i].BitMapsizeY = 32;
		AllData.ChangeItemPacket[i].Direction = Point(cos((rand() % 360) / 3.14), sin((rand() % 360) / 3.14));
		AllData.ChangeItemPacket[i].Pos.x = rand() % CLIENT_WIDTH;
		AllData.ChangeItemPacket[i].Pos.y = rand() % CLIENT_HEIGHT;
		AllData.ChangeItemPacket[i].State = ENUM_OBJSTATE::LIVE;
		AllData.ChangeItemPacket[i].ItemType = ENUM_ITEMTYPE::ITEM1;
	}
}
void CChangeItem::Create(HWND hWnd)
{

}
void CChangeItem::Render(HDC hdc)
{

}
void CChangeItem::collision()
{
	float temp;

	for (int i = 0; i < PLANET_MAX; ++i)
	{
		for (int j = 0; j < PLAYER_MAX; ++j)
		{
			if (Collision(AllData.ClientPacket[0].Pos, AllData.ChangeItemPacket[i].Pos, 30 ))
			{
				if (AllData.ClientPacket[0].PlayerHp > AllData.ClientPacket[1].PlayerHp)
				{
					AllData.ChangeItemPacket[i].State = ENUM_OBJSTATE::DIE;
					continue;
				}
				else
				{
					temp = AllData.ClientPacket[0].PlayerHp;
					AllData.ClientPacket[0].PlayerHp = AllData.ClientPacket[1].PlayerHp;
					AllData.ClientPacket[1].PlayerHp = temp;
					AllData.ChangeItemPacket[i].State = ENUM_OBJSTATE::DIE;
				}
			}
			if (Collision(AllData.ClientPacket[1].Pos, AllData.ChangeItemPacket[i].Pos, 30))
			{
				if (AllData.ClientPacket[1].PlayerHp > AllData.ClientPacket[0].PlayerHp)
				{
					AllData.ChangeItemPacket[i].State = ENUM_OBJSTATE::DIE;
					continue;
				}
				else
				{
					temp = AllData.ClientPacket[0].PlayerHp;
					AllData.ClientPacket[0].PlayerHp = AllData.ClientPacket[1].PlayerHp;
					AllData.ClientPacket[1].PlayerHp = temp;
					AllData.ChangeItemPacket[i].State = ENUM_OBJSTATE::DIE;
				}
				
			}
		}
	}
}
void CChangeItem::Update(const float ftime)
{
	//
	for (int i = 0; i < CHANGEITEM_MAX; ++i)
	{
		AllData.ChangeItemPacket[i].BitMapID = "ChangeItem";
	}
	for (int i = 0; i < CHANGEITEM_MAX; ++i)
	{
		if (AllData.ChangeItemPacket[i].Pos.x < 0 || AllData.ChangeItemPacket[i].Pos.x > CLIENT_WIDTH || AllData.ChangeItemPacket[i].Pos.y < 0 || AllData.ChangeItemPacket[i].Pos.y > CLIENT_HEIGHT)
		{
			AllData.ChangeItemPacket[i].State = ENUM_OBJSTATE::DIE;
		}
		AllData.ChangeItemPacket[i].Pos += AllData.ChangeItemPacket[i].Direction  * 0.5;
	}
	for (int i = 0; i < CHANGEITEM_MAX; ++i)
	{
		if (AllData.ChangeItemPacket[i].State == ENUM_OBJSTATE::LIVE)
		{
			continue;
		}
		if (AllData.ChangeItemPacket[i].State == ENUM_OBJSTATE::DIE)
		{
			AllData.ChangeItemPacket[i].BitMapcolor = RGB(255, 255, 255);
			AllData.ChangeItemPacket[i].BitMapsizeX = 32;
			AllData.ChangeItemPacket[i].BitMapsizeY = 32;
			AllData.ChangeItemPacket[i].BitMapID = "ChangeItem";

			AllData.ChangeItemPacket[i].Direction = Point(cos((rand() % 360) / 3.14), sin((rand() % 360) / 3.14));
			AllData.ChangeItemPacket[i].Pos.x = rand() % CLIENT_HEIGHT;
			AllData.ChangeItemPacket[i].Pos.y = rand() % CLIENT_HEIGHT;
			AllData.ChangeItemPacket[i].State = ENUM_OBJSTATE::LIVE;
		}
	}
	collision();
}

void CChangeItem::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

}
void CChangeItem::Release()
{
}
CChangeItem::~CChangeItem()
{
}

void CChangeItem::update()
{

}