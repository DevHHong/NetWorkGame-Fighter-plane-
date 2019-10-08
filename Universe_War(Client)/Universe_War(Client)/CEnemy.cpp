#include "stdafx.h"
#include "CEnemy.h"


CEnemy::CEnemy()
{
	mBitInfo = BitInfo("Player2U", 64, 64, RGB(255, 255, 255));
	pos.x = 700, pos.y = CLIENT_HEIGHT / 2;
	Speed = 150.f;
	dir = Point(0, 0);
	state = ENUM_OBJSTATE::LIVE;
	client = ENUM_CLIENT::NUM2;
	if (client == ENUM_CLIENT::NUM1)
		mBitInfo.ID = "Player1U";
	else if (client == ENUM_CLIENT::NUM2)
		mBitInfo.ID = "Player2U";
	enumDir = ENUM_DIRECTION::UP;
	Hp = MaxHp = 100;
	state = ENUM_OBJSTATE::LIVE;
}

CEnemy::~CEnemy()
{
}

void CEnemy::Create(HWND hWnd)
{
}

void CEnemy::Render(HDC hdc)
{
	if (state == ENUM_OBJSTATE::LIVE)
	{
		TransparentBlt(hdc, pos.x - (mBitInfo.sizeX / 2), pos.y - (mBitInfo.sizeY / 2),
			mBitInfo.sizeX, mBitInfo.sizeY, (*m_pMapBmp)[mBitInfo.ID]->GetMemDC(),
			0, 0, mBitInfo.sizeX, mBitInfo.sizeY, mBitInfo.color);
	}
	HpRender(hdc);
}

void CEnemy::Update(const float ftime)
{
	if (Hp <= 0)
	{
		state = ENUM_OBJSTATE::DIE;
		return;
	}
}

void CEnemy::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void CEnemy::Release()
{
}

void CEnemy::HpRender(HDC hdc)
{
	HBRUSH m_br = CreateSolidBrush(RGB(0, 0, 255));
	HBITMAP Ahbmp = CreateCompatibleBitmap(hdc, 100, 100);
	HDC Ahdc = CreateCompatibleDC(hdc);
	HBITMAP Aoldbmp = (HBITMAP)SelectObject(Ahdc, Ahbmp);
	auto oldbr = SelectObject(Ahdc, m_br);
	Rectangle(Ahdc, 0, 0, 100, 100);
	SelectObject(Ahdc, oldbr);
	BLENDFUNCTION bf;

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = 150;

	float hpRate = Hp / MaxHp;				// 현재 hp 비율
	float start = 0;						// 시작 점
	float end = 200;						// 끝점
	int curHp = int(start * (1.f - hpRate) + end * hpRate);		// 선형보간법 공식

	AlphaBlend(hdc, 590 + (end - curHp), 25, 800, 30, Ahdc, 0, 0, 100, 100, bf);
	SelectObject(Ahdc, Aoldbmp);
	DeleteObject(m_br);
	DeleteObject(Ahbmp);
	DeleteDC(Ahdc);

	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 200));
	HPEN oldPen = (HPEN)SelectObject(hdc, hPen);
	auto old = SelectObject(hdc, GetStockObject(NULL_BRUSH));
	Rectangle(hdc, 600, 25, 800, 55);
	SelectObject(hdc, old);
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}
