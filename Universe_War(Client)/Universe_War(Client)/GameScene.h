#pragma once
#include "Scene.h"
#include "BackGround.h"


class CPlayer;
class CPlanet;
class CItem;
class CMissile;

class CGameScene : public CScene
{
public:
	CBackGround mBackGround;

	CPlayer* mpPlayer{ nullptr };
	CPlanet* mpPlanet[PLANET_MAX] = { nullptr };
	float planetCreateTime{ 0 };
	CItem* mpItem[ITEM_MAX] = { nullptr };
	float itemCreateTime{ 0 };
	CMissile* mpMissile[MISSILE_MAX] = { nullptr };
	float missileCreateTime{ 0 };

public:
	CGameScene();
	virtual ~CGameScene();

	virtual void Create(HWND hWnd) override;
	virtual void Render(HDC hdc) override;
	virtual void Update(const float ftime) override;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void Release() override;

	
};

