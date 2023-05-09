#ifndef	PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <time.h>

class	PmergeMe
{
	public:
		PmergeMe();
		virtual	~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe&	operator=(const PmergeMe &other);

		template<typename T>
		static void	Sort(T& container);
		
	private:

};

#endif
