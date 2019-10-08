#pragma once
#include "GameObj.h"
class CPlanet : public CGameObj
{
public:
	CPlanet();
	virtual ~CPlanet();

	virtual void Create(HWND hWnd) override;
	virtual void Render(HDC hdc) override;
	virtual void Update(const float ftime) override;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void Release() override;
	void Init();
	void collision();
	Point getPos();
	float getRange();
private:
	static CPlanet* Instance;
public:
	static CPlanet* GetInstance()
	{
		if (NULL == Instance)
			Instance = new CPlanet();
		return Instance;
	}

};

