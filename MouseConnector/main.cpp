#include <windows.h>
#include <winuser.h>
#include <iostream>
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的   

int main()
{
    unsigned long interval = 1;//默认间隔时间1ms
    cout << "Please input interval time(ms), input [Enter] to end:";
    cin >> interval;

    Sleep(3000);
    POINT cursorPos;
    GetCursorPos(&cursorPos);//获取鼠标光标位置

    while (true)
    {
        Sleep(interval);//单位：毫秒
        mouse_event(MOUSEEVENTF_LEFTDOWN, cursorPos.x, cursorPos.y, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, cursorPos.x, cursorPos.y, 0, 0);

        if (KEY_DOWN(MOUSE_EVENT))
        {
            break;
        }

    }

    return 0;

}