#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	/*
	 *	Abstract class should not be instantiable
	 */ 
	// AAnimal	*base = new AAnimal();
	// base->makeSound();

	AAnimal	*i = new Cat();
	AAnimal	*j = new Dog();

	i->makeSound();	
	j->makeSound();

	delete i;
	delete j;

	return (0);
}
