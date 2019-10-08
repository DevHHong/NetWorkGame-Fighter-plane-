#include "stdafx.h"
#include "Missile.h"

//SingleTone
CMissile* CMissile::Instance = NULL;
CMissile::CMissile()
{
}

CMissile::CMissile(Point p, ENUM_DIRECTION d)
{
	
}

CMissile::~CMissile()
{ 
}

void CMissile::Create(HWND hWnd)
{
}
void CMissile::Init()
{

}
void CMissile::Render(HDC hdc)
{
	for (int i = 0; i < MISSILE_MAX; ++i)
	{
		if (AllData.MissilePacket[i].State == ENUM_OBJSTATE::LIVE   )
		{
			TransparentBlt
			(
				hdc,
				AllData.MissilePacket[i].Pos.x,
				AllData.MissilePacket[i].Pos.y,
				AllData.MissilePacket[i].BitMapsizeX,
				AllData.MissilePacket[i].BitMapsizeY,
				(*m_pMapBmp)[AllData.MissilePacket[i].BitMapID]->GetMemDC(),
				0,
				0,
				AllData.MissilePacket[i].BitMapsizeX,
				AllData.MissilePacket[i].BitMapsizeY,
				AllData.MissilePacket[i].BitMapcolor
			);
		}
	}

}

void CMissile::Update(const float ftime)
{
	
}

void CMissile::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void CMissile::Release()
{
}
