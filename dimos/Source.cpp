#include <iostream>
#include <windows.h>
#include "dll.h"
#include <conio.h>
using namespace std;

static LPCWSTR name = L"{A60BEA33-3EF-4992-BC72-8ADB80BDD080}";

int main() {
	auto a = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(int), name);
	set(a);
	_getch();
	drop();
	return 0;
}