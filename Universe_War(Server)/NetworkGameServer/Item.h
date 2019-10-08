#pragma once
#include "GameObj.h"
class CItem : public CGameObj
{
protected:
	float curTime{ 0 };
	ENUM_ITEMTYPE itemType;
public:
	CItem();
	virtual ~CItem();

	virtual void Create(HWND hWnd) override final;
	virtual void Render(HDC hdc) override final;
	virtual void Update(const float ftime) override final;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override final;
	virtual void Release() override final;

	void ItemCreate();

	ENUM_ITEMTYPE getItemType()const { return itemType; }


private:
	static CItem* Instance;
public:
	static CItem* GetInstance()
	{
		if (NULL == Instance)
			Instance = new CItem();
		return Instance;
	}
};

