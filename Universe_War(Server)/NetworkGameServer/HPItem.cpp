#include "pch.h"
#include "HpItem.h"

//SingleTone
CHpItem* CHpItem::Instance = NULL;

CHpItem::CHpItem()
{

}
void CHpItem::Init()
{
	for (int i = 0; i < HPITEM_MAX; ++i)
	{
		AllData.HpItemPacket[i].BitMapID = "HpItem";
		AllData.HpItemPacket[i].BitMapcolor = RGB(255, 255, 255);
		AllData.HpItemPacket[i].BitMapsizeX = 32;
		AllData.HpItemPacket[i].BitMapsizeY = 32;
		AllData.HpItemPacket[i].Direction = Point(cos((rand() % 360) / 3.14), sin((rand() % 360) / 3.14));
		AllData.HpItemPacket[i].Pos.x = rand() % CLIENT_WIDTH;
		AllData.HpItemPacket[i].Pos.y = rand() % CLIENT_HEIGHT;
		AllData.HpItemPacket[i].State = ENUM_OBJSTATE::LIVE;
		AllData.HpItemPacket[i].ItemType = ENUM_ITEMTYPE::ITEM1;
	}


}
void CHpItem::collision()
{
	for (int i = 0; i < HPITEM_MAX; ++i)
	{
		for (int j = 0; j < PLAYER_MAX; ++j)
		{
			if (Collision(AllData.ClientPacket[j].Pos, AllData.HpItemPacket[i].Pos, 30))
			{
				AllData.ClientPacket[j].PlayerHp = AllData.ClientPacket[j].PlayerMaxHp;
				AllData.HpItemPacket[i].State = ENUM_OBJSTATE::DIE;
			}
		}
	}
}
void CHpItem::Create(HWND hWnd)
{

}
void CHpItem::Render(HDC hdc)
{

}
void CHpItem::Update(const float ftime)
{
	for (int i = 0; i < HPITEM_MAX; ++i)
	{
		AllData.HpItemPacket[i].BitMapID = "HpItem";
	}
	for (int i = 0; i < HPITEM_MAX; ++i)
	{
		if (AllData.HpItemPacket[i].Pos.x < 0 || AllData.HpItemPacket[i].Pos.x > CLIENT_WIDTH || AllData.HpItemPacket[i].Pos.y < 0 || AllData.HpItemPacket[i].Pos.y > CLIENT_HEIGHT)
		{
			AllData.HpItemPacket[i].State = ENUM_OBJSTATE::DIE;
		}
		AllData.HpItemPacket[i].Pos += AllData.HpItemPacket[i].Direction  * 0.5;
	}
	for (int i = 0; i < HPITEM_MAX; ++i)
	{
		if (AllData.HpItemPacket[i].State == ENUM_OBJSTATE::LIVE)
		{
			continue;
		}
		if (AllData.HpItemPacket[i].State == ENUM_OBJSTATE::DIE)
		{
			AllData.HpItemPacket[i].BitMapcolor = RGB(255, 255, 255);
			AllData.HpItemPacket[i].BitMapsizeX = 32;
			AllData.HpItemPacket[i].BitMapsizeY = 32;
			AllData.HpItemPacket[i].BitMapID = "HpItem";

			AllData.HpItemPacket[i].Direction = Point(cos((rand() % 360) / 3.14), sin((rand() % 360) / 3.14));
			AllData.HpItemPacket[i].Pos.x = rand() % CLIENT_HEIGHT;
			AllData.HpItemPacket[i].Pos.y = rand() % CLIENT_HEIGHT;
			AllData.HpItemPacket[i].State = ENUM_OBJSTATE::LIVE;
		}
	}
	collision();
}

void CHpItem::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

}
void CHpItem::Release()
{
}
CHpItem::~CHpItem()
{
}


void CHpItem::update()
{

}