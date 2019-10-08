#include "pch.h"
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

}
void CPlanet::Init()
{
	//NetWork
	for (int i = 0; i < PLANET_MAX; ++i)
	{
		AllData.PlanetPacket[i].BitMapcolor = RGB(255, 255, 255);
		AllData.PlanetPacket[i].BitMapsizeX = 50;
		AllData.PlanetPacket[i].BitMapsizeY = 50;
		AllData.PlanetPacket[i].Damage = 10.f;
		AllData.PlanetPacket[i].Direction = Point(cos((rand() % 360) / 3.14), sin((rand() % 360) / 3.14));
		AllData.PlanetPacket[i].Pos.x = rand() % CLIENT_HEIGHT;
		AllData.PlanetPacket[i].Pos.y = rand() % CLIENT_HEIGHT;
		AllData.PlanetPacket[i].Speed = 5;
		AllData.PlanetPacket[i].State = ENUM_OBJSTATE::LIVE;
	}
}

void CPlanet::collision()
{
	for (int i = 0; i < PLANET_MAX; ++i)
	{
		for (int j = 0; j < PLAYER_MAX; ++j)
		{
			if (Collision(AllData.ClientPacket[j].Pos, AllData.PlanetPacket[i].Pos, AllData.ClientPacket[j].BitMapsizeX / 2 + AllData.PlanetPacket[i].BitMapsizeX / 2))
			{
				AllData.ClientPacket[j].PlayerHp -= 15;
				AllData.PlanetPacket[i].State = ENUM_OBJSTATE::DIE;
			}
		}
	}
}
void CPlanet::Update(const float ftime)
{
	for (int i = 0; i < PLANET_MAX; ++i)
	{
		AllData.PlanetPacket[i].BitMapID = "Planet";
	}
	for (int i = 0; i < PLANET_MAX; ++i)
	{
		if (AllData.PlanetPacket[i].Pos.x < 0 || AllData.PlanetPacket[i].Pos.x > CLIENT_WIDTH || AllData.PlanetPacket[i].Pos.y < 0 || AllData.PlanetPacket[i].Pos.y > CLIENT_HEIGHT)
		{
			AllData.PlanetPacket[i].State = ENUM_OBJSTATE::DIE;
		}
		AllData.PlanetPacket[i].Pos += AllData.PlanetPacket[i].Direction  * 0.5;
	}
	for (int i = 0; i < PLANET_MAX; ++i)
	{
		if (AllData.PlanetPacket[i].State == ENUM_OBJSTATE::LIVE)
		{
			continue;
		}
		if (AllData.PlanetPacket[i].State == ENUM_OBJSTATE::DIE)
		{
			AllData.PlanetPacket[i].BitMapcolor = RGB(255, 255, 255);
			AllData.PlanetPacket[i].BitMapsizeX = 50;
			AllData.PlanetPacket[i].BitMapsizeY = 50;
			AllData.PlanetPacket[i].BitMapID = "Planet";

			AllData.PlanetPacket[i].Damage = 10.f;
			AllData.PlanetPacket[i].Direction = Point(cos((rand() % 360) / 3.14), sin((rand() % 360) / 3.14));
			AllData.PlanetPacket[i].Pos.x = rand() % CLIENT_HEIGHT;
			AllData.PlanetPacket[i].Pos.y = rand() % CLIENT_HEIGHT;
			AllData.PlanetPacket[i].Speed = 5;
			AllData.PlanetPacket[i].State = ENUM_OBJSTATE::LIVE;
		}
	}
	collision();
}

void CPlanet::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

}

void CPlanet::Release()
{
}
