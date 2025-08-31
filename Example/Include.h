#pragma once
#include <Windows.h>
#include <string>
namespace CS2 {
	using GetOffsetFunc = DWORD(*)(std::string);
	// Game dir is optional! If not provided, source2gen's steam game path resolver will be used!
	// if provided make sure its the root game dir, not any bin dir! for example: 
	// "D:\SteamLibrary\steamapps\common\Counter-Strike Global Offensive"
	__declspec(dllimport)  GetOffsetFunc SetupCSchemaSystem(bool log, std::string gameDir = {});
}