#pragma once

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#pragma warning(disable : 4002)	//	to many actual parameters for macro
#pragma warning(disable : 4091) // dbghelp.h 
#pragma warning(disable : 4668)
#pragma warning(disable : 4710)
#pragma warning(disable : 4777) // _snprintf %i
#pragma warning(disable : 4477) // _snprintf %#010x
#pragma warning(disable : 4820)
#pragma warning(disable : 4826)	//	conversion from 'unsigned long *' to DWORD64 is sign-extended
#pragma warning(disable : 4917)
#include <windows.h>

#include <memory>

#include "gost.h"

using namespace gost;