#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
 * If variables are initialized using new, parent class methods
 * can't be accessed using scope resolution operator (::)
 */
int	main(void)
{
	// const Animal	*meta = new Animal();
	// const Animal	*i = new Cat();
	// const Animal	*j = new Dog();

	// std::cout << i->getType() << " " << std::endl;
	// std::cout << j->getType() << " " << std::endl;
	// meta->makeSound();
	// i->makeSound();
	// j->makeSound();

	const WrongAnimal *nonmeta = new WrongCat();
	nonmeta->makeSound();

	return (0);
}
