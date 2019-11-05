#include <iostream>
#include <windows.h>
using namespace std;
using callbackfun = void(void);

void input_char(char* input)
{
    while (*input != '\0')
        keybd_event(*input++, 0, 0, 0);
}

void createprocess(LPCWSTR path, callbackfun clbfun)
{
    STARTUPINFO si;
    memset(&si, 0, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_SHOW;
    PROCESS_INFORMATION pi;
    if (CreateProcess(path,
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    ))
    {
        clbfun();
    }
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
}

void start_NerveMain()
{
    createprocess(TEXT("D:\\Compass\\NerveMain\\NerveMain.exe"), []()
        {
            HWND hwnd = FindWindow(NULL, TEXT("用户登录"));
            while (!hwnd) { hwnd = FindWindow(NULL, TEXT("用户登录")); }
            SetForegroundWindow(hwnd);
            char Username[] = { "LITONGYANG" };
            char Password[] = { "GOOGLE123" };
            keybd_event(VK_TAB, 0, KEYEVENTF_EXTENDEDKEY, 0);
            keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
            input_char(Username);
            keybd_event(VK_TAB, 0, KEYEVENTF_EXTENDEDKEY, 0);
            keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
            input_char(Password);
            keybd_event(VK_RETURN, 0, KEYEVENTF_EXTENDEDKEY, 0);
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
            while (hwnd) { hwnd = FindWindow(NULL, TEXT("用户登录")); }
        });
}

void start_WavMain()
{
    createprocess(TEXT("D:\\Compass\\WavMain\\WavMain.exe"), []()
    {
        HWND hwnd = FindWindow(NULL, TEXT("回避插件校验"));
        while (!hwnd) { hwnd = FindWindow(NULL, TEXT("回避插件校验")); }
        SetForegroundWindow(hwnd);
        keybd_event(VK_MBUTTON, 0, KEYEVENTF_EXTENDEDKEY, 0);
        keybd_event(VK_MBUTTON, 0, KEYEVENTF_KEYUP, 0);

        hwnd = FindWindow(NULL, TEXT("获取数字签名证书"));
        while (!hwnd) { hwnd = FindWindow(NULL, TEXT("获取数字签名证书")); }
        SetForegroundWindow(hwnd); Sleep(1000);
        keybd_event(VK_LBUTTON, 0, KEYEVENTF_EXTENDEDKEY, 0);
        keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
    });
}

void start_QQ()
{
    createprocess(TEXT("C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe"), []()
    {
        HWND hwnd = FindWindow(NULL, TEXT("QQ"));
        while (!hwnd) { hwnd = FindWindow(NULL, TEXT("QQ")); }
        SetForegroundWindow(hwnd);
        while (hwnd) 
        {
            hwnd = FindWindow(NULL, TEXT("QQ"));
            keybd_event(VK_TAB, 0, KEYEVENTF_EXTENDEDKEY, 0);
            keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_DOWN, 0, KEYEVENTF_EXTENDEDKEY, 0);
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_RETURN, 0, KEYEVENTF_EXTENDEDKEY, 0);
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
        }
    });
}

void start_DebugView()
{
    createprocess(TEXT("D:\\CustomFolder\\Private\\Tool\\DebugView-4.77\\Dbgview.exe"), []()
    {
    });
}

void start_VS()
{
    system("\"C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Professional\\Common7\\IDE\\devenv.exe\"");
    //system("\"C:\\Program Files (x86)\\Microsoft Visual Studio\\Common\\MSDev98\\Bin\\MSDEV.EXE\""); 
}

int main()
{
    start_NerveMain();
}
