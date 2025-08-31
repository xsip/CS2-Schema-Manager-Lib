#pragma once
#include <Windows.h>
#include <string>
#pragma comment(lib, "Dumper.lib")
namespace CS2 {
	using GetOffsetFunc = DWORD(*)(std::string);
	__declspec(dllimport)  GetOffsetFunc SetupCSchemaSystem(bool log, std::string gameDir = {});
}