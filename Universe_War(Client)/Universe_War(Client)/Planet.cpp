#include "stdafx.h"
#include "Planet.h"

//SingleTone
CPlanet* CPlanet::Instance = NULL;

CPlanet::CPlanet()
{
	

}

CPlanet::~CPlanet()
{
}

void CPlanet::Create(HWND hWnd)
{
	
}

void CPlanet::Render(HDC hdc)
{
	connect = 0;
	for (int j = 0; j < PLAYER_MAX; ++j)
	{
		if (AllData.ClientPacket[j].connect == true)
		{
			connect++;
		}
	}
	for (int i = 0; i < PLANET_MAX; ++i)
	{
		if (AllData.PlanetPacket[i].State == ENUM_OBJSTATE::LIVE /*&& connect == 2*/)
		{
			TransparentBlt
			(
				hdc,
				AllData.PlanetPacket[i].Pos.x,
				AllData.PlanetPacket[i].Pos.y,
				AllData.PlanetPacket[i].BitMapsizeX,
				AllData.PlanetPacket[i].BitMapsizeY,
				(*m_pMapBmp)[AllData.PlanetPacket[i].BitMapID]->GetMemDC(),
				0,
				0,
				AllData.PlanetPacket[i].BitMapsizeX,
				AllData.PlanetPacket[i].BitMapsizeY,
				RGB(255, 255, 255)
			);
		}
	}
}

void CPlanet::Update(const float ftime)
{
	
	
}

void CPlanet::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void CPlanet::Release()
{
}
