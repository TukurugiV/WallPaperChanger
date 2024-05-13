#include <windows.h>
#include <Vfw.h>

int main() {
    HWND desktop = GetDesktopWindow();
    HWND videoWnd = capCreateCaptureWindowA("MyVideo", WS_CHILD | WS_VISIBLE, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), desktop, 0);

    SendMessage(videoWnd, WM_CAP_DRIVER_CONNECT, 0, 0);
    SendMessage(videoWnd, WM_CAP_SET_SCALE, TRUE, 0);
    SendMessage(videoWnd, WM_CAP_SET_PREVIEWRATE, 66, 0);
    SendMessage(videoWnd, WM_CAP_SET_PREVIEW, TRUE, 0);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DestroyWindow(videoWnd);
    return 0;
}
