#pragma once
#include"Struct.h"

class ClientNetwork
{
private:

public:
	void Init();
	int recvn(SOCKET s, char* buf, int len, int flags);
	void err_display(const char* msg);
	void err_quit(const char* msg);
	void Render(HDC hdc);
	ENUM_CLIENT ClientID;
	All_Data ad;
	SOCKET sock;

public:
	ClientNetwork();
	~ClientNetwork();

private:
	static ClientNetwork* Instance;
public:
	static ClientNetwork* GetInstance()
	{
		if (NULL == Instance)
			Instance = new ClientNetwork();
		return Instance;
	}
};

