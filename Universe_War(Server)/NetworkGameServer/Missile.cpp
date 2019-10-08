#include "pch.h"
#include "Missile.h"


//SingleTone
CMissile* CMissile::Instance = NULL;

CMissile::CMissile()
{
}
CMissile::~CMissile()
{
}
CMissile::CMissile(Point p, ENUM_DIRECTION d)
{
	for (int i = 0; i < MISSILE_MAX; ++i)
	{
		AllData.MissilePacket[i].BitMapcolor = RGB(255, 255, 255);
		AllData.MissilePacket[i].BitMapID = "Missile";
		AllData.MissilePacket[i].BitMapsizeX = 38;
		AllData.MissilePacket[i].BitMapsizeY = 38;
		AllData.MissilePacket[i].Pos = p;
		
		AllData.MissilePacket[i].State = ENUM_OBJSTATE::LIVE;
		if (d == ENUM_DIRECTION::LEFT)
		{
			AllData.MissilePacket[i].Direction = Point(-1, 0);
		}

		else if (d == ENUM_DIRECTION::RIGHT)
		{
			AllData.MissilePacket[i].Direction = Point(1, 0);
		}

		else if (d == ENUM_DIRECTION::UP)
		{
			AllData.MissilePacket[i].Direction = Point(0, -1);
		}

		else if (d == ENUM_DIRECTION::DOWN)
		{
			AllData.MissilePacket[i].Direction = Point(0, 1);
		}
	}
}

void CMissile::CreateInit(Point p, ENUM_DIRECTION d)
{

	for (int i = 0; i < MISSILE_MAX; ++i)
	{
		AllData.MissilePacket[i].BitMapcolor = RGB(255, 255, 255);
		AllData.MissilePacket[i].BitMapID = "Missile";
		AllData.MissilePacket[i].BitMapsizeX = 38;
		AllData.MissilePacket[i].BitMapsizeY = 38;
		AllData.MissilePacket[i].Pos = p;

		AllData.MissilePacket[i].State = ENUM_OBJSTATE::LIVE;
		if (d == ENUM_DIRECTION::LEFT)
		{
			AllData.MissilePacket[i].Direction = Point(-1, 0);
		}

		else if (d == ENUM_DIRECTION::RIGHT)
		{
			AllData.MissilePacket[i].Direction = Point(1, 0);
		}

		else if (d == ENUM_DIRECTION::UP)
		{
			AllData.MissilePacket[i].Direction = Point(0, -1);
		}

		else if (d == ENUM_DIRECTION::DOWN)
		{
			AllData.MissilePacket[i].Direction = Point(0, 1);
		}
	}
}
void CMissile::Init()
{
	for (int i = 0; i < MISSILE_MAX; ++i)
	{
		AllData.MissilePacket[i].BitMapcolor = RGB(255, 255, 255);
		AllData.MissilePacket[i].BitMapID = "Missile";
		AllData.MissilePacket[i].BitMapsizeX = 38;
		AllData.MissilePacket[i].BitMapsizeY = 38;
		AllData.MissilePacket[i].State = ENUM_OBJSTATE::LIVE;
		AllData.MissilePacket[i].Direction = Point(cos((rand() % 360) / 3.14), sin((rand() % 360) / 3.14));
		if (ClientPacket.PlayerID == ENUM_CLIENT::NUM1)
		{
			AllData.MissilePacket[i].Pos.x = AllData.ClientPacket[0].Pos.x;
			AllData.MissilePacket[i].Pos.y = AllData.ClientPacket[0].Pos.y;
		}	
		else if (ClientPacket.PlayerID == ENUM_CLIENT::NUM2)
		{
			AllData.MissilePacket[i].Pos.x = AllData.ClientPacket[1].Pos.x;
			AllData.MissilePacket[i].Pos.y = AllData.ClientPacket[1].Pos.y;
		}
	}
}



void CMissile::Create(HWND hWnd)
{
}

void CMissile::Render(HDC hdc)
{

}

void CMissile::Update(const float ftime)
{
	for (int i = 0; i < MISSILE_MAX; ++i)
	{
		AllData.MissilePacket[i].BitMapcolor = RGB(255, 255, 255);
		AllData.MissilePacket[i].BitMapID = "Missile";
		AllData.MissilePacket[i].BitMapsizeX = 38;
		AllData.MissilePacket[i].BitMapsizeY = 38;
		AllData.MissilePacket[i].State = ENUM_OBJSTATE::LIVE;

		if (ClientPacket.PlayerID == ENUM_CLIENT::NUM1)
		{
			AllData.MissilePacket[i].Pos.x = AllData.ClientPacket[0].Pos.x + (i * 15);
			AllData.MissilePacket[i].Pos.y = AllData.ClientPacket[0].Pos.y + (i * 8);
		}
		if (ClientPacket.PlayerID == ENUM_CLIENT::NUM2)
		{
		
			AllData.MissilePacket[i].Pos.x = AllData.ClientPacket[1].Pos.x + cosf(i * 15);
			AllData.MissilePacket[i].Pos.y = AllData.ClientPacket[1].Pos.y + -sinf(i * 8);
		}

		if (AllData.MissilePacket[i].Pos.x < 0 || AllData.MissilePacket[i].Pos.x > CLIENT_WIDTH || AllData.MissilePacket[i].Pos.y < 0 || AllData.MissilePacket[i].Pos.y > CLIENT_HEIGHT)
		{
			AllData.MissilePacket[i].State = ENUM_OBJSTATE::DIE;
		}
	}
}
void CMissile::ShootMissile()
{
	for (int i = 0; i < MISSILE_MAX; ++i)
	{
		AllData.MissilePacket[i].BitMapcolor = RGB(255, 255, 255);
		AllData.MissilePacket[i].BitMapID = "Missile";
		AllData.MissilePacket[i].BitMapsizeX = 38;
		AllData.MissilePacket[i].BitMapsizeY = 38;
		AllData.MissilePacket[i].State = ENUM_OBJSTATE::LIVE;

		if (ClientPacket.PlayerID == ENUM_CLIENT::NUM1)
		{
			AllData.MissilePacket[i].Pos.x = AllData.ClientPacket[0].Pos.x + (i * 15);
			AllData.MissilePacket[i].Pos.y = AllData.ClientPacket[0].Pos.y +(i*8);
		}
		if (ClientPacket.PlayerID == ENUM_CLIENT::NUM2)
		{
			AllData.MissilePacket[i].Pos.x = AllData.ClientPacket[1].Pos.x + (i * 15);
			AllData.MissilePacket[i].Pos.y = AllData.ClientPacket[1].Pos.y + (i * 8);
		}
		if (AllData.MissilePacket[i].Pos.x < 0 || AllData.MissilePacket[i].Pos.x > CLIENT_WIDTH || AllData.MissilePacket[i].Pos.y < 0 || AllData.MissilePacket[i].Pos.y > CLIENT_HEIGHT)
		{
			AllData.MissilePacket[i].State = ENUM_OBJSTATE::DIE;
		}
		
	}
}
void CMissile::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void CMissile::Release()
{
}
