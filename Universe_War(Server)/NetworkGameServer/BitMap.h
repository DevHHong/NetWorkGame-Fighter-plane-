#pragma once
class CBitMap
{
private:
	HDC			m_hdc, m_MemDC;
	HBITMAP		m_bitMap, m_oldBitMap;
public:
	CBitMap();
	virtual ~CBitMap();

	CBitMap* LoadBmp(HWND hwnd, PTCHAR pFileName);
	void Release();

	HDC GetMemDC() const { return m_MemDC; }

private:
	static CBitMap* m_hInstance;
public:
	static CBitMap* Instance()
	{
		if (m_hInstance == nullptr)
			m_hInstance = new CBitMap();
		return m_hInstance;
	}

	void Destroy()
	{
		if (m_hInstance != nullptr)
		{
			delete m_hInstance;
			m_hInstance = nullptr;
		}
	}
};

