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
#include <map >

namespace SDK {
	class CSchemaManagerField {
	public:
		DWORD GetOffset();
		const char* GetType();
	};

	class CSchemaManagerClass {
	public:
		CSchemaManagerField* GetField(std::string fieldName);
		std::map<const char*, CSchemaManagerField*> GetAllFields();
		bool HasBaseClass();
		const char* GetName();
		uintptr_t GetPtr();
		CSchemaManagerClass* GetBaseClass();
	};

	class CSchemaManagerModule {
	public:
		CSchemaManagerClass* GetClass(std::string className);
		std::map<const char*, CSchemaManagerClass*> GetAllClasses();
	};

}

namespace CS2 {

	class Dumper {
	public:
		DWORD GetOffsetFast(std::string szSchemaPath);
		SDK::CSchemaManagerModule* GetModule(std::string moduleName);
		std::map <const char*, SDK::CSchemaManagerModule*> GetAllModules();

	};

	// Game dir is optional! If not provided, source2gen's steam game path resolver will be used!
	// if provided make sure its the root game dir, not any bin dir! for example: 
	// "D:\SteamLibrary\steamapps\common\Counter-Strike Global Offensive"
	__declspec(dllimport)  Dumper* SetupCSchemaSystem(bool log, std::string gameDir = {});
}
```

### After that you can simple obtain offsets.

Main.cpp
```c++
#include "Include.h"
int main() {
	auto dumper = CS2::SetupCSchemaSystem(true);
	// Gettings offsets fast by selector
	printf("m_iHealth: 0x%x\n", dumper->GetOffsetFast("client->C_BaseEntity->m_iHealth"));

	// mapping through "client.dll" class list
	auto classList = dumper->GetModule("client")->GetAllClasses();
	for (const auto classData : classList) {	
		if (strcmp(classData.first, "C_BaseEntity") == 0) {
			printf("Class: %s | Base: %s\n", classData.first, classData.second->GetBaseClass()->GetName());

			auto fieldList = classData.second->GetAllFields();
			for (const auto fieldData : fieldList) {
				printf("\tField: %s ( 0x%x )\n", fieldData.first, fieldData.second->GetOffset());
			}
		}
	}
}


}


```

# Example Output:
![Example Output](https://raw.githubusercontent.com/xsip/CS2-Schema-Manager-Lib/refs/heads/main/Output.png "Example Output")


# Reference Projects

[Source2Gen](https://github.com/neverlosecc/source2gen "Source2Gen") - For Game Directory Resolver
