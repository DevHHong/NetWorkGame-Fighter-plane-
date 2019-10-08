#pragma once

class CGameFramework;
class CBitMap;

class CScene
{
protected:
	map<string, CBitMap*> m_MapBmp;
public:
	CScene();
	virtual ~CScene();

	virtual void Create(HWND hWnd) = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Update(const float ftime) = 0;
	virtual void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
	virtual void Release() = 0;

protected:
	void CreateBitMapPath(HWND hWnd);
};

