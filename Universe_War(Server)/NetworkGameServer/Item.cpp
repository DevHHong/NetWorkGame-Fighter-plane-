#include "pch.h"
#include "Item.h"
//SingleTone
CItem* CItem::Instance = NULL;

CItem::CItem()
{

}

CItem::~CItem()
{
}

void CItem::Create(HWND hWnd)
{
}

void CItem::Render(HDC hdc)
{
	//������. ������ �ʿ� x

	/*TransparentBlt(hdc, pos.x - (mBitInfo.sizeX / 2), pos.y - (mBitInfo.sizeY / 2),
		mBitInfo.sizeX, mBitInfo.sizeY, (*m_pMapBmp)[mBitInfo.ID]->GetMemDC(),
		0, 0, mBitInfo.sizeX, mBitInfo.sizeY, mBitInfo.color);*/
}

void CItem::Update(const float ftime)
{
	
}

void CItem::ItemCreate()
{

}

void CItem::Message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void CItem::Release()
{
}
