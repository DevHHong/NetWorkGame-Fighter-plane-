#include "pch.h"
#include "GameFramework.h"
#include "GameScene.h"

CGameFramework::CGameFramework()
{
}

CGameFramework::~CGameFramework()
{
	/*famework쪽에서 릴리즈를 하여 소멸하기 때문에 빼준다. */
	//Release();
}

void CGameFramework::Create(HWND hWnd)
{
	m_hWnd = hWnd;
	ChangeScene(ENUM_SCENEID::GAMESCENE);

	if (m_pScene) m_pScene->Create(hWnd);
}

void CGameFramework::Render(HDC hdc) const
{
	if (m_pScene) m_pScene->Render(hdc);
}

void CGameFramework::Update(const float ftime)
{
	if (m_SceneID != ENUM_SCENEID::END)
	{
		ChangeScene_FW(m_SceneID);
		m_SceneID = ENUM_SCENEID::END;
	}
	if (m_pScene) m_pScene->Update(ftime);
}

void CGameFramework::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pScene)
		m_pScene->Message(hWnd, message, wParam, lParam);
}

void CGameFramework::Release()
{
	if (m_pScene)
	{
		m_pScene->Release();
		delete m_pScene;
		m_pScene = nullptr;
	}
}

void CGameFramework::ChangeScene(ENUM_SCENEID sceneID)
{
	m_SceneID = sceneID;
}

void CGameFramework::ChangeScene_FW(ENUM_SCENEID sceneID)
{
	Release();

	switch (sceneID)
	{
	case ENUM_SCENEID::GAMESCENE:
		m_pScene = new CGameScene();
		break;
	}
	if (m_pScene)m_pScene->Create(m_hWnd);
}
