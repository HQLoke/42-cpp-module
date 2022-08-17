#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	random;

	srand(time(0));
	random = rand() % 3;
	switch (random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "\"A\"" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "\"B\"" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "\"C\"" << std::endl;
		return ;
	}
	std::cout << "Unidentified type" << std::endl;
}

void	identify(Base &p)
{
	identify(&p);
}

int main(void)
{
	Base	*a = new A();
	Base	*b = new B(); 
	Base	*c = new C();
	Base	*d = NULL;
	Base	*random = generate();

	std::cout << "|--------------------|" << std::endl
			  << "|       Pointer      |" << std::endl
			  << "|--------------------|" << std::endl;
	identify(a);
	identify(b);
	identify(c);
	identify(d);

	std::cout << "|----------------------|" << std::endl
			  << "|       Reference      |" << std::endl
			  << "|----------------------|" << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);
	identify(*d);

	std::cout << "|-------------------|" << std::endl
			  << "|       Random      |" << std::endl
			  << "|-------------------|" << std::endl;
	identify(random);
	identify(*random);

	delete a;
	delete b;
	delete c;
	delete d;
	delete random;
	
	return (0);
}
