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
	std::cout << "|-----------------------------------|" << std::endl;
	std::cout << "|       Test given in the PDF       |" << std::endl;
	std::cout << "|-----------------------------------|" << std::endl;

	const Animal	*meta = new Animal();
	const Animal	*i = new Cat();
	const Animal	*j = new Dog();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();

	delete meta;
	delete i;
	delete j;
	
	std::cout << "----------------------------------------------" << std::endl;

	const WrongAnimal	*nonmeta = new WrongCat();

	std::cout << nonmeta->getType() << std::endl;
	nonmeta->makeSound();

	delete nonmeta;

	return (0);
}
