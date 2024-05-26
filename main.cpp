#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void moveMouse(int x, int y) {
    SetCursorPos(x, y);
}

void leftClick() {
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void rightClick() {
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}

bool RightHeldAlt() {
    Sleep(7);
    if (GetAsyncKeyState(VK_RMENU) & 0x8000) {
        return true;
    }
    return false;
}

int main() {
	
	HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE); 

    if (ifstream("disable.txt")) {
        return 0;
    }
	
    int x = 500;
    int y = 500;
    bool leftClicked = false;
    bool rightClicked = false;

    while (true) {
		
		if(RightHeldAlt() == true){
        if (GetAsyncKeyState('I') & 0x8000) {
            y -= 9;
        }
        if (GetAsyncKeyState('K') & 0x8000) {
            y += 9;
        }
        if (GetAsyncKeyState('J') & 0x8000) {
            x -= 9;
        }
        if (GetAsyncKeyState('L') & 0x8000) {
            x += 9;
        }
        if (GetAsyncKeyState('U') & 0x8000 && !leftClicked) {
            leftClick();
            leftClicked = true;
        }
        else if (!(GetAsyncKeyState('U') & 0x8000)) {
            leftClicked = false;
        }
        if (GetAsyncKeyState('O') & 0x8000 && !rightClicked) {
            rightClick();
            rightClicked = true;
        }
        else if (!(GetAsyncKeyState('O') & 0x8000)) {
            rightClicked = false;
        }
        moveMouse(x, y);
    }
	}
    return 0;
}