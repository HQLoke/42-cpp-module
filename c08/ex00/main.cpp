#include "easyfind.hpp"
#include "easyfind.tpp"
#include "colour.h"

int	main(void)
{
	const int	size = 1000;

	std::cout << "|-------------------|" << std::endl;
	std::cout << "|       Array       |" << std::endl;
	std::cout << "|-------------------|" << std::endl;
	std::array<int, size> arr;

	for (int i = 0; i < size; i += 1)
		arr[i] = i;
	for (int i = 995; i < 1005; i += 1)
	{
		std::array<int, size>::iterator ite;
		try
		{
			ite = easyFind(arr, i);
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			continue ;
		}
		std::cout << GREEN << "Found: " << *ite << RESET << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "|--------------------|" << std::endl;
	std::cout << "|       Vector       |" << std::endl;
	std::cout << "|--------------------|" << std::endl;
	std::vector<int> vec;

	for (int i = 0; i < size; i += 1)
		vec.push_back(i);

	for (int i = 995; i < 1005; i += 1)
	{
		std::vector<int>::iterator ite;
		try
		{
			ite = easyFind(vec, i);
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			continue ;
		}
		std::cout << GREEN << "Found: " << *ite << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << "|-------------------|" << std::endl;
	std::cout << "|       Deque       |" << std::endl;
	std::cout << "|-------------------|" << std::endl;
	std::deque<int> deq;

	for (int i = 0; i < size; i += 1)
		deq.push_back(i);

	for (int i = 995; i < 1005; i += 1)
	{
		std::deque<int>::iterator ite;
		try
		{
			ite = easyFind(deq, i);
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			continue ;
		}
		std::cout << GREEN << "Found: " << *ite << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "|       Forward List       |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::forward_list<int> forlist;

	for (int i = 0; i < size; i += 1)
		forlist.push_front(i);

	for (int i = 995; i < 1005; i += 1)
	{
		std::forward_list<int>::iterator ite;
		try
		{
			ite = easyFind(forlist, i);
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			continue ;
		}
		std::cout << GREEN << "Found: " << *ite << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << "|------------------|" << std::endl;
	std::cout << "|       List       |" << std::endl;
	std::cout << "|------------------|" << std::endl;
	std::list<int> ls;

	for (int i = 0; i < size; i += 1)
		ls.push_front(i);

	for (int i = 995; i < 1005; i += 1)
	{
		std::list<int>::iterator ite;
		try
		{
			ite = easyFind(ls, i);
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			continue ;
		}
		std::cout << GREEN << "Found: " << *ite << RESET << std::endl;
	}
}
