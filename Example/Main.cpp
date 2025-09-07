#include "Include.h"

int main() {
	auto dumper = CS2::SetupCSchemaSystem(true);
	// Gettings offsets fast by selector
	printf("m_iHealth: 0x%x\n", dumper->GetOffsetFast("client->C_BaseEntity->m_iHealth"));

	// mapping through "client.dll" class list
	auto classList = dumper->GetModule("client")->GetAllClasses();
	for (const auto classData : classList) {	
		if (classData.first == "C_BaseEntity") {
			printf("Class: %s::%s | 0x%p ( Base: %s::%s )\n", classData.second->GetModuleName(), classData.second->GetName(), classData.second->GetPtr(), classData.second->GetBaseClass()->GetModuleName(), classData.second->GetBaseClass()->GetName());

			auto fieldList = classData.second->GetAllFields();
			for (const auto fieldData : fieldList) {
				printf("\tField: %s ( 0x%x | %s )\n", fieldData.first.c_str(), fieldData.second->GetOffset(), fieldData.second->GetType());
			}
		}
	}
}

