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

#pragma comment(lib, "Dumper.lib")

namespace CS2 {
	using GetOffsetFunc = DWORD(*)(std::string);
	__declspec(dllimport)  GetOffsetFunc SetupCSchemaSystem(bool log);
}
```

### After that you can simple obtain offsets.

Main.cpp
```c++
#include "Include.h"

int main() {
	auto GetOffset = CS2::SetupCSchemaSystem(true);
	printf("m_iHealth: 0x%x\n", GetOffset("client->C_BaseEntity->m_iHealth"));
}
```

# Example Output:
![Example Output](https://raw.githubusercontent.com/xsip/CS2-Schema-Manager-Lib/refs/heads/main/Output.png "Example Output")


# Reference Projects

[Source2Gen](https://github.com/neverlosecc/source2gen "Source2Gen") - For Game Directory Resolver
