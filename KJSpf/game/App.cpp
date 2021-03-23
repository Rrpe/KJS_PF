// KJSpf.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "App.h"
#include "iWindow.h"

#define MAX_LOADSTRING 100

// 전역 변수:
WCHAR szTitle[MAX_LOADSTRING] = TEXT("KJSpf");;                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING] = TEXT("KJSpf");            // 기본 창 클래스 이름입니다.
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND hWnd;
HDC hDC;
bool runWnd;

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KJSPF));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_KJSPF);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    RegisterClassExW(&wcex);

    // 애플리케이션 초기화를 수행합니다:
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
    hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
    if (hWnd == NULL)
        return FALSE;

    hDC = GetDC(hWnd);

    //ULONG_PTR token = startApp(hDC);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);


    MSG msg;
    // 기본 메시지 루프입니다:
    for (runWnd = true; runWnd;)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            //drawApp();
        }
    }

    //endApp(token);
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
        case WM_CREATE:
        {
            xprintf("cmd_create\n");
            xprintf("utf8 적용\n");
            return 0; // break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0; // break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
