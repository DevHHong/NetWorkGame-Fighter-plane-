#pragma once


/*============================DEFINE================================*/
// 윈도우 크기
#define CLIENT_WIDTH		800
#define CLIENT_HEIGHT		600

// 객체 최고 개수
#define PLANET_MAX			5
#define ITEM_MAX			5
#define HPITEM_MAX			1
#define CHANGEITEM_MAX		1
#define MISSILE_MAX			10
#define PLAYER_MAX			2

//네트워크
#define SERVERPORT	9000
#define IP			"192.168.121.252"
#define BUFSIZE		50000

#define K_UP 1
#define K_DOWN 2
#define K_RIGHT 3
#define K_LEFT 4

// Scene
enum class ENUM_SCENEID :UINT
{
	GAMESCENE,
	OVERSCENE,
	END
};

enum class ENUM_OBJSTATE :UINT
{
	LIVE,
	DIE,
	WIN,
	LOSE,
	NONE
};

enum class ENUM_CLIENT :UINT
{
	NUM1,
	NUM2,
	NONE
};

enum class ENUM_DIRECTION :UINT
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NONE
};

enum class ENUM_ITEMTYPE : UINT
{
	ITEM1,
	ITEM2,
	NONE
};
/*============================STRUCT================================*/

typedef struct Client_Packet
{
	ENUM_DIRECTION enumDir;
	Point Pos;
	float PlayerHp;
	float PlayerMaxHp;
	float Attack;
	Point Dir;
	ENUM_CLIENT PlayerID;
	bool UseHpChangeItem;
	bool UseHpGainItem;
	ENUM_OBJSTATE State;
	bool GameStart;
	int DirKey;
	bool connect;
	bool ShootMissile;

	//비트맵 정보들	
	int BitMapsizeX;
	int BitMapsizeY;
	DWORD BitMapcolor;
	std::string BitMapID;

	//아이템들 정보
	BitInfo ITEMUI[2];
	ENUM_ITEMTYPE ITEMTYPE[2];
	
}Client_Packet;

typedef struct Planet_Packet
{
	Point Direction;
	Point Pos;
	float Speed;
	float Damage;
	ENUM_OBJSTATE State;

	//비트맵 정보들	
	int BitMapsizeX;
	int BitMapsizeY;
	DWORD BitMapcolor;
	std::string BitMapID;
}Planet_Packet;


typedef struct HpItem_Packet
{
	Point Pos;
	Point Direction;
	ENUM_OBJSTATE State;
	ENUM_ITEMTYPE ItemType;
	float CurTime;

	//비트맵 정보들	
	int BitMapsizeX;
	int BitMapsizeY;
	DWORD BitMapcolor;
	std::string BitMapID;
}HpItem_Packet;
typedef struct ChangeItem_Packet
{
	Point Pos;
	Point Direction;
	ENUM_OBJSTATE State;
	ENUM_ITEMTYPE ItemType;
	float CurTime;

	//비트맵 정보들	
	int BitMapsizeX;
	int BitMapsizeY;
	DWORD BitMapcolor;
	std::string BitMapID;
}ChangeItem_Packet;
typedef struct Missile_Packet
{
	Point Pos;
	Point Direction;
	ENUM_OBJSTATE State;

	//비트맵 정보들	
	int BitMapsizeX;
	int BitMapsizeY;
	DWORD BitMapcolor;
	std::string BitMapID;
}Missile_Packet;

//Extern
extern Client_Packet ClientPacket;
extern Planet_Packet PlanetPacket;
extern HpItem_Packet HpItemPacket;
extern ChangeItem_Packet ChangeItemPacket;
extern Missile_Packet MissilePacket;

typedef struct All_Data
{
	Client_Packet ClientPacket[PLAYER_MAX];
	Planet_Packet PlanetPacket[PLANET_MAX];
	HpItem_Packet HpItemPacket[ITEM_MAX];
	ChangeItem_Packet ChangeItemPacket[ITEM_MAX];
	Missile_Packet MissilePacket[MISSILE_MAX];
	int ID;
	bool GameStart;
	int GameOver;
}All_Data;


extern All_Data AllData;
//==================================================Network=================================================