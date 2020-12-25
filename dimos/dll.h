#pragma once
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DLLWITHHOOK_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DLLWITHHOOK_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLLWITHHOOK_EXPORTS
#define DLLWITHHOOK_API __declspec(dllexport)
#else
#define DLLWITHHOOK_API __declspec(dllimport)
#endif

// This class is exported from the dll-with-hook.dll
class DLLWITHHOOK_API Cdllwithhook {
public:
	Cdllwithhook(void);
	// TODO: add your methods here.
};

extern DLLWITHHOOK_API int ndllwithhook;

DLLWITHHOOK_API int fndllwithhook(void);

DLLWITHHOOK_API void set(HANDLE);
DLLWITHHOOK_API void drop();
