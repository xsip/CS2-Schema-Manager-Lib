#include "Include.h"

int main() {
	auto GetOffset = CS2::SetupCSchemaSystem(true);
	printf("m_iHealth: 0x%x\n", GetOffset("client->C_BaseEntity->m_iHealth"));
}