 //ConsoleDoubleBuffering.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include <stdio.h>
#include "System.h"

	
	extern bool g_bQuit;	 // 나갔는 지 아닌지 확인하는 변수
	extern COORD g_Player;   // 플레이어 위치 
	
	
	int main()
	{
		consoleRender::ScreenInit();				// 현재 스크린의 커서 피킹 현상 방지 
		
				
		Time::InitTime();							// 현재 타이머 시간 초기화 

		while (g_bQuit != true)						// Escape 로 나가지 않았을 때 반복 시킨다. 
		{
			Time::UpdateTime();
			Input::Update();
			
		

		};
		
		consoleRender::ScreenRelease(); // 스크린 버퍼 닫아주기 
	}
		
	/*void Update()
	{
			
		if (g_Player.X < 0) g_Player.X = 0;
		if (g_Player.X >= ConsoleRenderer::ScreenWidth()) g_Player.X = ConsoleRenderer::ScreenWidth() - 1;
		if (g_Player.Y < 0) g_Player.Y = 0;
		if (g_Player.Y >= ConsoleRenderer::ScreenHeight()) g_Player.Y = ConsoleRenderer::ScreenHeight() - 1;
	}*/

	
	
	
	/*void Render()
	{
		ConsoleRenderer::ScreenClear();
	
		char buf[256] = { 0, };
		float time = Time::GetTotalTime();
		sprintf_s(buf, "ConsoleRandomGame 시작 이후의 시간: %f", Time::GetTotalTime());
	
		ConsoleRenderer::ScreenDrawString(0, 0, buf, FG_PINK_DARK);
		ConsoleRenderer::ScreenDrawString(0, 1, L"ConsoleRandomGame", FG_PINK_DARK);
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, L'A', FG_WHITE);
	
		ConsoleRenderer::ScreenFlipping();
	}*/
