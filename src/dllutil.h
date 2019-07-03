#pragma once

#ifdef _WINDOWS

#include <SDKDDKVer.h>

#ifdef INI_EXPORTS
#define EXPORT_INI __declspec(dllexport)
#else
#define EXPORT_INI __declspec(dllimport) void HelloWorld();
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#else

#define EXPORT_INI

#endif
