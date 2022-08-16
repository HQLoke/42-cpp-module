#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// Test given in the PDF
	{
		// const Animal *i = new Cat();
		// const Animal *j = new Dog();

		// i->makeSound();
		// j->makeSound();

		// delete i;
		// delete j;
		// system("leaks animal");
	}

	// Creation and destruction of an array of Animal objects
	{
		// const int	size = 100;
		// Animal		*zoo[size];

		// for (int i = 0; i < size; i += 1)
		// {
		// 	std::cout << i + 1 << ": ";
		// 	if (i % 2 == 0)
		// 		zoo[i] = new Cat();
		// 	else
		// 		zoo[i] = new Dog();
		// }

		// for (int i = 0; i < size; i += 1)
		// {
		// 	std::cout << i + 1 << ": ";
		// 	delete zoo[i];
		// }

		// system("leaks animal");
	}

	// Shallow and deep copy test
	{
		// Dog	*original = new Dog();
		// Dog	*copy;

		// original->getBrain()->setIdeas("Meat");

		// copy = original;
		// delete original;

		// copy->getBrain()->printIdeas();
		// system("leaks animal");
	}

	return (0);
}
