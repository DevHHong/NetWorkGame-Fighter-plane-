#pragma once
class CScene;

class CGameFramework
{
	CScene* m_pScene{ nullptr };
	HWND m_hWnd;
	ENUM_SCENEID m_SceneID{ ENUM_SCENEID::END };
public:
	CGameFramework();
	virtual ~CGameFramework();

	void Create(HWND hWnd);
	void Render(HDC hdc) const;
	void Update(const float ftime);
	void Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void Release();

	void ChangeScene(ENUM_SCENEID sceneID);
private:
	void ChangeScene_FW(ENUM_SCENEID sceneID);
};

