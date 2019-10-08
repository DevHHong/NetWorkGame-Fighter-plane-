#pragma once
#include "GameObj.h"



class CPlayer : public CGameObj
{
	BitInfo ItemUI[2];
	ENUM_ITEMTYPE itemType[2];
	int itemCnt{ 0 };
public:
	CPlayer();
	virtual ~CPlayer();

	virtual void Create(HWND hWnd) override;
	virtual void Render(HDC hdc) override;
	virtual void Update(const float ftime) override;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void Release() override;

private:
	void HpRender(HDC hdc);
	void ItemRender(HDC hdc);
public:
	void SetItemType(ENUM_ITEMTYPE t) { itemType[itemCnt++] = t; }
	int getItemCnt()const { return itemCnt; }
	//
public:	
	float getHp();
	Point getPos();
	float getRange();
	void setState(ENUM_OBJSTATE s);
	void setDamage(float d);
	//
private:
	static CPlayer* Instance;
public:
	static CPlayer* GetInstance()
	{
		if (NULL == Instance)
			Instance = new CPlayer();
		return Instance;
	}
};

