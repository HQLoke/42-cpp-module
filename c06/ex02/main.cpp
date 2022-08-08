#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	random;

	srand(time(0));
	random = 1 + rand() % 3;
	switch (random)
	{
		case 1:
			return (new A());
		case 2:
			return (new B());
		case 3:
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
	Base *a = new A();
	Base *b = new B(); 
	Base *c = new C();
	Base *d = NULL;

	std::cout << "Using pointer as argument" << std::endl;
	identify(a);
	identify(b);
	identify(c);
	identify(d);

	std::cout << "\n" << std::endl;

	std::cout << "Using reference as argument" << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);
	identify(*d);
}
