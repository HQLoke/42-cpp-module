#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// AAnimal *base = new AAnimal();
	AAnimal *i = new Cat();
	AAnimal *j = new Dog();

	// base->makeSound();
	i->makeSound();	
	j->makeSound();

	return (0);
}
