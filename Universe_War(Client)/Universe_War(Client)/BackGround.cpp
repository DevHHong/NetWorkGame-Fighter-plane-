#include "stdafx.h"
#include "BackGround.h"


CBackGround::CBackGround()
{
}


CBackGround::~CBackGround()
{
}

void CBackGround::Create(HWND hWnd)
{
}

void CBackGround::Render(HDC hdc)
{
	BitBlt(hdc, 0, 0, CLIENT_WIDTH, CLIENT_HEIGHT, (*m_pMapBmp)["BackGround"]->GetMemDC(), 0, 0, SRCCOPY);
}

void CBackGround::Update(const float ftime)
{
}

void CBackGround::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void CBackGround::Release()
{
}
