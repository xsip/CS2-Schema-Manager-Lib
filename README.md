# CS2-SchemaManager-Lib
### CS2 SchemaManager Lib is a C++ Library for getting SchemaSystem offsets fast in Counter Strike 2.
### This could be used for external Cheats!

# Usage
### Just include the header, add the DLL to your executable file folder and link the library.


Include.h
```c++
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
```

### After that you can simple obtain offsets.

Main.cpp
```c++
#include "Include.h"

int main() {
	auto GetOffset = CS2::SetupCSchemaSystem(true);
	// with game path:
	// auto GetOffset = CS2::SetupCSchemaSystem(true, "D:\SteamLibrary\steamapps\common\Counter-Strike Global Offensive");
	printf("m_iHealth: 0x%x\n", GetOffset("client->C_BaseEntity->m_iHealth"));
}
```

# Example Output:
![Example Output](https://raw.githubusercontent.com/xsip/CS2-Schema-Manager-Lib/refs/heads/main/Output.png "Example Output")


# Reference Projects

[Source2Gen](https://github.com/neverlosecc/source2gen "Source2Gen") - For Game Directory Resolver
