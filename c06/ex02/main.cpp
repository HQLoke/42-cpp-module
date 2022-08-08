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
	// bool	match;

	// match = true;
	// try
	// {
	// 	A	&a = dynamic_cast<A&>(p);
	// 	(void)a;
	// }
	// catch (std::bad_cast &e)
	// {
	// 	match = false;
	// }
	// catch (std::N)
	// if (match == true)
	// {
	// 	std::cout << "Object referenced to by p: \"A\"" << std::endl;
	// 	return ;
	// }
	// match = true;
	// try
	// {
	// 	B	&b = dynamic_cast<B&>(p);
	// 	(void)b;
	// }
	// catch (std::bad_cast &e)
	// {
	// 	match = false;
	// }
	// if (match == true)
	// {
	// 	std::cout << "Object referenced to by p: \"B\"" << std::endl;
	// 	return ;
	// }
	// match = true;
	// try
	// {
	// 	C	&c = dynamic_cast<C&>(p);
	// 	(void)c;
	// }
	// catch (std::bad_cast &e)
	// {
	// 	match = false;
	// }
	// if (match == true)
	// {
	// 	std::cout << "Object referenced to by p: \"C\"" << std::endl;
	// 	return ;
	// }
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

	std::cout << "\n\n" << std::endl;

	std::cout << "Using reference as argument" << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);
	identify(*d);
}
