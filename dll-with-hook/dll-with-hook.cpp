// dll-with-hook.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "dll-with-hook.h"

static LPCWSTR name = L"{A60BEA33-3EF-4992-BC72-8ADB80BDD080}";
// This is an example of an exported variable
DLLWITHHOOK_API int ndllwithhook=0;

// This is an example of an exported function.
DLLWITHHOOK_API int fndllwithhook(void)
{
    return 42;
}

Cdllwithhook::Cdllwithhook()
{
    return;
}

static HANDLE sharedMemoryHnd;
static bool* pointer;
static bool a;

LRESULT CALLBACK callback(int code, WPARAM w, LPARAM l) {
	sharedMemoryHnd = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, name);
	pointer = (bool*)MapViewOfFile(sharedMemoryHnd, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if ((*pointer)) {
		*pointer = false;
		MessageBox(NULL, L"HUI", L"HUI", MB_OKCANCEL);
		*pointer = true;
		Sleep(300);
		//*pointer = false;
	}
	return CallNextHookEx(h, code, w, l);
}


DLLWITHHOOK_API void set(HANDLE handle) {
	Sleep(100);
	h = SetWindowsHookEx(WH_CBT, callback, module, 0);
	sharedMemoryHnd = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, name);
	pointer = (bool*)MapViewOfFile(sharedMemoryHnd, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	*pointer = true;
}

DLLWITHHOOK_API void drop() {
	UnhookWindowsHookEx(h);
}
