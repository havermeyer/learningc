#include <windows.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MessageBoxA(NULL, "Goodbye, cruel world!", "Note", MB_OK);
    return 0;
}