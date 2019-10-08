#pragma once
#include "GameObj.h"
class CChangeItem : public CGameObj
{
public:
	CChangeItem();
	virtual ~CChangeItem();
	void update();
	void Init();
	virtual void Create(HWND hWnd) override;
	virtual void Render(HDC hdc) override;
	virtual void Update(const float ftime) override;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void Release() override;
	void collision();
private:
	static CChangeItem* Instance;
public:
	static CChangeItem* GetInstance()
	{
		if (NULL == Instance)
			Instance = new CChangeItem();
		return Instance;
	}
};

