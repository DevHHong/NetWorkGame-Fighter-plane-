#pragma once
#include "GameObj.h"
class CEnemy :public CGameObj
{
public:
	CEnemy();
	virtual ~CEnemy();

	virtual void Create(HWND hWnd) override;
	virtual void Render(HDC hdc) override;
	virtual void Update(const float ftime) override;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void Release() override;

private:
	void HpRender(HDC hdc);
};

