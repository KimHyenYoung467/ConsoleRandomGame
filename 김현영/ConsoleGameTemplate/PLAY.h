#pragma once
#include "ConsoleRenderer.h"
#include <stdio.h>
#include "Input.h"
#include "System.h"
#include "ConsoleGameTemplate.cpp"



namespace Play
{
	//Todo 플레이어 캐릭터가 9초에 3점을 획득하지 못할 시에 사망에 이르게 된다.
	//Todo Escape 키를 눌렀을 때, b_Quit = true 일 때, END 창에서 즉시 스크린 버퍼와 화면 출력 콘솔창을 삭제 해버린다.
	struct score
	{
		int Score; 
		int score_width;
		int score_height;

	} SC;
	int screenwidth_X = consoleRender::ScreenWidth();
	int screenheight_Y = consoleRender::ScreenHeight();

	// ���� �÷��� ���� ��, �ʱ�ȭ �Ǿ� �־�� ��. 
	char* map = new char[screenheight_Y * screenwidth_X + screenwidth_X];    // 2���� �迭
	
	void Initialize();											// Scene ó�� ������ �� ���� �� �Լ� 
	
	void Update();												// Play �� ��� ������Ʈ �Ǿ�� �� �͵� 
	void Render();

	// Play �� ��� ������ �Ǿ�� �� �͵�
	void RandomScore();											// ���ھ �������� ��Ÿ���� �Ѵ�.
	void Map();													// ���� �׸��� �Լ�
	void MoveCheck(short* X, short* Y, int x, int y);			// �÷��̾��� �������� �޾Ƽ� ó���ϴ� �Լ� 
	void ScorePlusMinus();

	void GameComplete(); 
	void GameOver(); 

	
	bool isPlaying = false;										// ������ ���� ������ �ƴ��� Ȯ���ϴ� ���� 
	bool isCrash = false; 										// �÷��̾ ���� �ε������� Ȯ���ϴ� ����						// �÷��̾ ���� �ε������� Ȯ���ϴ� ���� 
}
