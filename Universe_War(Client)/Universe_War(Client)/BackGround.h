#pragma once
#include "GameObj.h"
class CBackGround : public CGameObj
{
public:
	CBackGround();
	virtual~CBackGround();

	virtual void Create(HWND hWnd) override;
	virtual void Render(HDC hdc) override;
	virtual void Update(const float ftime) override;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void Release() override;
};

