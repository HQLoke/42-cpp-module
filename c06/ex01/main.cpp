#include <Data.hpp>

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data		original;
	uintptr_t	serialized;
	Data		*temp;
	
	original.value = 42;

	serialized = serialize(&original);
	std::cout << "Serialized data: " << serialized << std::endl;

	temp = deserialize(serialized);
	std::cout << "\nPointer (original)    : " << &original << std::endl;
	std::cout << "Pointer (deserialized): " << temp << std::endl;

	std::cout << "\nData (original)    : " << original.value << std::endl;
	std::cout << "Data (deserialized): " << original.value << std::endl;
}
