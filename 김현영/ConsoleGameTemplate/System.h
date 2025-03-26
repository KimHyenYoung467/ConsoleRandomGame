#pragma once
#include <Windows.h>
#include "Input.h"
#include "Time.h"
#include "ConsoleRenderer.h"
#include "PLAY.h"
#include "MENU.h"

namespace System{

	enum SceneType { MENU, PLAY, END }; // �� Ÿ�� 

	SceneType SceneCurrent;					// ���� �� 
	SceneType* NextScene = nullptr;			// ���� �� 
	
	void SceneInit();

	void ChangeScene(SceneType new_scene);					     // ��Ȳ(�Է� �Ǵ� �ð� ����) �� ���� SceneNext ���� 
	void SceneUpdate();											 
	void SceneRender();											 // �ܼ�â�� �ؽ�Ʈ�� �׸��� 
	void ProcessInput();									   
	void NextChangeIndex(); 								   
															   
	//bool IsRunning() { return isRunning; };					 // ������ ���� ������ �ƴ��� Ȯ���ϴ� ������ ��ȯ�Ѵ�.

	SceneType GetSceneType(SceneType scene) { return scene = SceneCurrent; }; // ���� ���� �����´�.

}


