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

	class CSchemaManagerEnumProperty {
	public:
		const char* GetValue();
		const char* GetName();
	};

	class CSchemaManagerEnum {
	public:
		CSchemaManagerEnumProperty GetEnumerator(std::string fieldName);
		uintptr_t GetPtr();
		const char* GetModuleName();
		const char* GetName();
		const char* GetType();
		std::map<std::string, CSchemaManagerEnumProperty> GetAllEnumerators();
	};

	class CSchemaManagerClass {
	public:
		CSchemaManagerField* GetField(std::string fieldName);
		std::map<std::string, CSchemaManagerField*> GetAllFields();
		bool HasBaseClass();
		const char* GetName();
		const char* GetModuleName();
		uintptr_t GetPtr();
		uint32_t GetSize();
		CSchemaManagerClass* GetBaseClass();
	};

	class CSchemaManagerModule {
	public:
		CSchemaManagerClass* GetClass(std::string className);
		std::map<std::string, CSchemaManagerClass*> GetAllClasses();

		CSchemaManagerEnum* GetEnum(std::string szEnumName);
		std::map<std::string, CSchemaManagerEnum*> GetAllEnums();
	};

}

namespace CS2 {

	class Dumper {
	public:
		DWORD GetOffsetFast(std::string szSchemaPath);
		SDK::CSchemaManagerModule* GetModule(std::string moduleName);
		std::map <std::string, SDK::CSchemaManagerModule*> GetAllModules();

	};

	// Game dir is optional! If not provided, source2gen's steam game path resolver will be used!
	// if provided make sure its the root game dir, not any bin dir! for example: 
	// "D:\SteamLibrary\steamapps\common\Counter-Strike Global Offensive"
	__declspec(dllimport)  Dumper* SetupCSchemaSystem(bool log, std::string gameDir = {});
}
