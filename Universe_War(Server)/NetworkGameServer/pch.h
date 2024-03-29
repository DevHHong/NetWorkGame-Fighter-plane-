// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

#ifndef PCH_H
#define PCH_H

// TODO: 여기에 미리 컴파일하려는 헤더 추가

#endif //PCH_H


// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// 여기서 프로그램에 필요한 추가 헤더를 참조합니다.
#include <iostream>
#include <chrono>
#include <map>
#include <string>
#include<winsock.h>
#include<Windows.h>
#include<stdio.h>
#include<time.h>
#include<thread>
#pragma comment(lib,"ws2_32")


using namespace std;
#pragma comment(lib, "winmm.lib")

//이미지
#pragma comment(lib, "msimg32.lib")

// 비트맵 정보
struct BitInfo
{
	string ID;
	int sizeX;
	int sizeY;
	DWORD color;
	BitInfo() :ID{ 0 }, sizeX{ 0 }, sizeY{ 0 }, color{ 0 }{}
	BitInfo(string id, int x, int y, DWORD c) :ID{ id }, sizeX{ x }, sizeY{ y }, color{ c }{}
};
#include"Point.h"
#include"Struct.h"

#define SERVERPORT 9000
#define BUFSIZE 50000
