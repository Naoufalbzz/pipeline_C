#include <windows.h>

// Function declaration for the Window Procedure
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// Entry point of a Windows application
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    // Register the window class
    if (!RegisterClassW(&wc)) {
        return -1;
    }

    // Create the window
    CreateWindowW(L"myWindowClass", L"Hello World", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

    // Message loop
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Window Procedure: Handles events for the window
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // Here you can add drawing code
            TextOut(hdc, 100, 100, "Hello World", wcslen(L"Hello World"));
            EndPaint(hWnd, &ps);
            break;
        }
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}
