#include "System.h"



	void System::SceneInit()
	{
		consoleRender::ScreenInit();
	
		SceneCurrent = SceneType::MENU;
		
	}
	
	void System::SceneUpdate()
	{
		if (Input::IsKeyDown(true))
		{
			SceneType nextScene; // ���� �� ����  ���� 4byte
	
			if (!SceneCurrent) // ���� ���� �ƴ� �� 
			{
				NextChangeIndex();
				nextScene = SceneType::PLAY;
				ChangeScene(nextScene);
			}
			else if (SceneCurrent == SceneType::PLAY)
			{
				NextChangeIndex();
				nextScene = SceneType::END;
				ChangeScene(nextScene);
			}
			else if (nextScene == SceneType::END && g_bQuit == true )
			{
				printf("게임을 종료 하겠습니다.");
			} 
		}
	}
	
	void System::SceneRender()
	{
		consoleRender::ScreenClear();
	
		char* buf = { 0, }; 
		consoleRender::ScreenDrawString(0, 0, buf, FG_PINK_DARK);
	
		// ���� ���� ������ �����Ѵ�.
		ChangeScene(GetSceneType(SceneCurrent));
		
		// ���� ���� ��� 
		consoleRender::ScreenFlipping();
	}
	
	void System::ChangeScene(SceneType scenecurrent)
	{
		SceneCurrent = scenecurrent;
	
		switch (SceneCurrent)
		{
		case SceneType::MENU:
			SceneCurrent = SceneType::MENU;
			NextChangeIndex();
			MENU::MenuRender();
			break;
		case SceneType::PLAY:
			SceneCurrent = SceneType::PLAY;
			NextChangeIndex();
			Play::Render();  // PLAY �� ȣ�� 
			break;
		case SceneType::END:
			SceneCurrent = SceneType::END;
			break;
		}
	}
	void System::NextChangeIndex()
	{
		GetSceneType(SceneCurrent);

		if (SceneCurrent == NULL)
		{
			printf("���� ���� ����ֽ��ϴ�.");
			return;
		}
	
		// ���� ������ ������ �� ���� 
		for (int NextIndex = 0; NextIndex <= 3; ++NextIndex)
		{
			NextScene[NextIndex++];
		}
		return; 
	}
	
	void System::ProcessInput()
	{
		if (Input::IsKeyDown(VK_LEFT)) { //����
			g_Player.X--;
		}
		else if (Input::IsKeyDown(VK_RIGHT)) { //������
			g_Player.X++;
		}
		else if (Input::IsKeyDown(VK_UP)) { //��
			g_Player.Y--;
		}
		else if (Input::IsKeyDown(VK_DOWN)) { //�Ʒ�
			g_Player.Y++;
		}
		else if (Input::IsKeyDown(VK_ESCAPE)) { //����
			g_bQuit = true;
		}
		if (SceneCurrent == SceneType::MENU && getchar())
		{
			SceneCurrent = SceneType::PLAY;
		}
	
	}
	
