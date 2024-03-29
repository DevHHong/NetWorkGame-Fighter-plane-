// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 특정 포함 파일이 들어 있는
// 포함 파일입니다.
//

#pragma once
// 콘솔창 띄우기
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 
#endif
#include "targetver.h"

//#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
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


/*=============================ENUM=================================*/
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
#include "Point.h"
#include"Struct.h"
