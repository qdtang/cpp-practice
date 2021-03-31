#include <iostream>
#include <typeinfo>

#define ENABLE_ENUM_FLAG(EnumType) \
EnumType operator | (EnumType lhs, EnumType rhs) \
{ \
	return static_cast<EnumType>( \
	static_cast<std::underlying_type_t<EnumType>>(lhs) | \
	static_cast<std::underlying_type_t<EnumType>>(rhs)); \
} \
EnumType operator & (EnumType lhs, EnumType rhs) \
{ \
	return static_cast<EnumType>( \
	static_cast<std::underlying_type_t<EnumType>>(lhs) & \
	static_cast<std::underlying_type_t<EnumType>>(rhs)); \
} \
EnumType operator ~ (EnumType operand) \
{ \
	return static_cast<EnumType>(~static_cast<std::underlying_type_t<EnumType>>(operand)); \
} \
EnumType& operator |= (EnumType& lhs, EnumType rhs) \
{ \
	lhs = lhs | rhs; \
	return lhs; \
} \
EnumType& operator &= (EnumType& lhs, EnumType rhs) \
{ \
	lhs = lhs & rhs; \
	return lhs; \
} \
bool EnumType##IsSet(EnumType lhs, EnumType rhs) \
{ \
	return static_cast<bool>( \
	static_cast<std::underlying_type_t<EnumType>>(lhs) & \
	static_cast<std::underlying_type_t<EnumType>>(rhs)); \
}

enum class Permission 
{
	Readable = 0x1,
	Writable = 0x2,
	Executable = 0x4
};
ENABLE_ENUM_FLAG(Permission)

enum class AB : int8_t
{
	A = 0x1,
	B = 0x2
};
ENABLE_ENUM_FLAG(AB)

enum CDE 
{
	C = 0x1,
	D = 0x2,
	E = 0x4
};
ENABLE_ENUM_FLAG(CDE)

int main(int argc, char *argv[])
{
	Permission p1 = Permission::Readable | Permission::Writable;
	Permission p2 = Permission::Executable;
	p1 |= p2;  // enable flag
	p1 &= ~Permission::Writable; // disable flag
	bool readable = PermissionIsSet(p1, Permission::Readable); // check flag
	std::cout << static_cast<std::underlying_type_t<Permission>>(p1) << "\n";
	std::cout << std::boolalpha << readable << "\n";
	std::cout << std::is_same_v<std::underlying_type_t<Permission>, int> << "\n";

	bool check = ABIsSet(AB::A | AB::B, AB::B);
	std::cout << std::boolalpha << check << "\n";
	std::cout << std::is_same_v<std::underlying_type_t<AB>, int8_t> << "\n";

	check = CDEIsSet(CDE::C | CDE::E, CDE::D);
	std::cout << std::boolalpha << check << "\n";
	std::cout << std::is_same_v<std::underlying_type_t<CDE>, int> << "\n";  // !!false
	return 0;
}
