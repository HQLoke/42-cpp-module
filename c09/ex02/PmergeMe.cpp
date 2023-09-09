#include "PmergeMe.hpp"

/*
**	Constructor, destructor, copy constructor, copy assignment operator
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}
