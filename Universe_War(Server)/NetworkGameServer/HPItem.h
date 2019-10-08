#pragma once
#include "GameObj.h"

class CHpItem : public CGameObj
{
public:
	CHpItem();
	virtual ~CHpItem();
	void update();
	void Init();
	virtual void Create(HWND hWnd) override;
	virtual void Render(HDC hdc) override;
	virtual void Update(const float ftime) override;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void Release() override;
	void collision();
private:
	static CHpItem* Instance;
public:
	static CHpItem* GetInstance()
	{
		if (NULL == Instance)
			Instance = new CHpItem();
		return Instance;
	}
};