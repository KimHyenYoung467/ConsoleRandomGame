#include "MENU.h"

namespace MENU
{
    // �밡�� ���� �� �׸��� 

    void MenuInitialize() // �ʱ�ȭ �Լ� 
    {
        consoleRender::ScreenInit();
        
        //Todo 현재 씬을 MENU 씬으로 설정 
        System::SceneCurrent = System::SceneType::MENU;
        
        map[screenheight_Y * screenwidth_X + screenwidth_X] = 0;
    }

    void MenuUpdate()
    {
        //Todo 맵 그리기 
        MenuMAP();
    }

    void MenuRender()
    {
        consoleRender::ScreenClear(); 

        char buf[256] = { 0, };
        consoleRender::ScreenDrawString(0, 0, buf, FG_BLUE);

        MenuUpdate();

        consoleRender::Buffersinit(0,0, buf); //Todo 버퍼 찾기 
        
        consoleRender::ScreenDrawString(screenwidth_X / 2,screenheight_Y - 1, "아무 키나 입력하시면 게임 시작합니다.", FG_BLUE);
        getchar();
        System::ProcessInput(); 
		
        consoleRender::ScreenFlipping();

        System::NextChangeIndex();

        delete[] map; 
    }

    /********************************************************************************************************/

    // Menu Map 

    /********************************************************************************************************/

    void MenuMAP()
    {
        // �޴� ��ũ���� ��� �� �׸��� 
        printf("					/////////////       /////////////"); 
        printf("					//           //     //			  //"); 
        printf("					//           //     //			   //"); 
        printf("					//           //     //			   //"); 
        printf("					/////////////////////////////////////");
        printf("					//           //	    //			   //");
        printf("					//           //	    //			  //");
        printf("					//           //	    //			 //");
        printf("					//           //	     ////////////");

    }
	
}
