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
