#include "stdafx.h"
#include "HpItem.h"


//SingleTone
CHpItem* CHpItem::Instance = NULL;

CHpItem::CHpItem()
{

}
void CHpItem::Render(HDC hdc)
{
	connect = 0;
	for (int j = 0; j < PLAYER_MAX; ++j)
	{
		if (AllData.ClientPacket[j].connect == true)
		{
			connect++;
		}
	}
	for (int i = 0; i < HPITEM_MAX; ++i)
	{
		if (AllData.HpItemPacket[i].State == ENUM_OBJSTATE::LIVE && connect == 2)
		{
			TransparentBlt
			(
				hdc,
				AllData.HpItemPacket[i].Pos.x-13,
				AllData.HpItemPacket[i].Pos.y +10,
				AllData.HpItemPacket[i].BitMapsizeX,
				AllData.HpItemPacket[i].BitMapsizeY,
				(*m_pMapBmp)[AllData.HpItemPacket[i].BitMapID]->GetMemDC(),
				0,
				0,
				AllData.HpItemPacket[i].BitMapsizeX,
				AllData.HpItemPacket[i].BitMapsizeY,
				AllData.HpItemPacket[i].BitMapcolor
			);
		}
	}

}
CHpItem::~CHpItem()
{
}
void CHpItem::Create(HWND hWnd)
{

}

void CHpItem::Update(const float ftime)
{

}
void CHpItem::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

}
void CHpItem::Release()
{

}