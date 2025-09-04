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

