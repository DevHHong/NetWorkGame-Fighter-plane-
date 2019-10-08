#pragma once
#include "GameObj.h"
class CMissile : public CGameObj
{
public:
	CMissile();
	CMissile(Point p, ENUM_DIRECTION d);
	virtual ~CMissile();

	virtual void Create(HWND hWnd) override;
	virtual void Render(HDC hdc) override;
	virtual void Update(const float ftime) override;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void Release() override;
	void Init();
private:
	static CMissile* Instance;
public:
	static CMissile* GetInstance()
	{
		if (NULL == Instance)
			Instance = new CMissile();
		return Instance;
	}
};

