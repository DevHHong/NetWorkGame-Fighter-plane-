#pragma once
#include "BitMap.h"
class CGameObj
{
protected:
	static map<string, CBitMap*>* m_pMapBmp;
	BitInfo mBitInfo;
	Point pos;
	Point dir;
	ENUM_OBJSTATE state;
	ENUM_CLIENT	  client;
	ENUM_DIRECTION enumDir;
	float Hp{ 0 };
	float MaxHp{ 0 };
	float Speed{ 0 };
	float Damage{ 0 };
public:
	CGameObj();
	virtual ~CGameObj();

	virtual void Create(HWND hWnd) = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Update(const float ftime) = 0;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
	virtual void Release() = 0;

	static void SetBmp(map<string, CBitMap*>* bmp) { m_pMapBmp = bmp; }		// Scene에 있는 Bitmap정보를 가져오기

	const ENUM_OBJSTATE& getState()const { return state; }
	ENUM_DIRECTION getEnumDir()const { return enumDir; }
	Point getPos()const { return pos; }
	float getHp()const { return Hp; }
	float getRange()const { return mBitInfo.sizeX / 2.f; }
	float getDamage()const { return Damage;}
	void setState(ENUM_OBJSTATE s) { state = s; }
	void setDamage(float d) { Hp -= d; }
};

