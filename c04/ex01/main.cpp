#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		// Animal *zoo[2];

		// for (int i = 0; i < 2; i += 1)
		// {
		// 	if (i % 2 == 0)
		// 		zoo[i] = new Cat();
		// 	else
		// 		zoo[i] = new Dog();
		// }

		// for (int i = 0; i < 2; i += 1)
		// {
		// 	delete zoo[i];
		// }

		// system("leaks animal");
	}

	{
		// Dog	*original = new Dog();
		// Dog	*copy;

		// original->getBrain()->setIdeas("WTF");
		// copy = original;
		// delete original;

		// copy->getBrain()->printIdeas();
		// system("leaks animal");
	}

	// PDF test
	{
		// const Animal *i = new Cat();
		// const Animal *j = new Dog();

		// i->makeSound();
		// j->makeSound();

		// delete i;
		// delete j;
		// system("leaks animal");
	}

	return (0);
}
