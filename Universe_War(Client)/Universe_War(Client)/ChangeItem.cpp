#include "stdafx.h"
#include "ChangeItem.h"

//SingleTone
CChangeItem* CChangeItem::Instance = NULL;

CChangeItem::CChangeItem()
{

}
void CChangeItem::Render(HDC hdc)
{
	connect = 0;
	for (int j = 0; j < PLAYER_MAX; ++j)
	{
		if (AllData.ClientPacket[j].connect == true)
		{
			connect++;
		}
	}
	for (int i = 0; i < CHANGEITEM_MAX; ++i)
	{
		if (AllData.ChangeItemPacket[i].State == ENUM_OBJSTATE::LIVE && connect == 2)
		{
			TransparentBlt
			(
				hdc,
				AllData.ChangeItemPacket[i].Pos.x - 13,
				AllData.ChangeItemPacket[i].Pos.y + 10,
				AllData.ChangeItemPacket[i].BitMapsizeX,
				AllData.ChangeItemPacket[i].BitMapsizeY,
				(*m_pMapBmp)[AllData.ChangeItemPacket[i].BitMapID]->GetMemDC(),
				0,
				0,
				AllData.ChangeItemPacket[i].BitMapsizeX,
				AllData.ChangeItemPacket[i].BitMapsizeY,
				AllData.ChangeItemPacket[i].BitMapcolor
			);
		}
	}
}
CChangeItem::~CChangeItem()
{
}
void CChangeItem::Create(HWND hWnd)
{

}

void CChangeItem::Update(const float ftime)
{

}
void CChangeItem::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

}
void CChangeItem::Release()
{

}