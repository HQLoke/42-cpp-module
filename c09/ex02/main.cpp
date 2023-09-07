#include "PmergeMe.hpp"

#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned int	isPositiveInt(const char *token)
{
	int	len;

	len = strlen(token);
	for (int i = 0; i < len; i += 1)
	{
		if (token[i] < '0' || token[i] > '9')
		{
			std::cout << "Error" << std::endl;
			exit (1);
		}
	}
	return (atoi(token));
}

double			timeDiff(struct timespec begin, struct timespec end)
{
	long	seconds;
	long	nanoseconds;
	double	elapsed;

	seconds = end.tv_sec - begin.tv_sec;
	nanoseconds = end.tv_nsec - begin.tv_nsec;
	elapsed = seconds * 1e9 + nanoseconds;
	return (elapsed * 1e-3);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "No elements are given as input." << std::endl;
		return (1);
	}

	/* ---------------------------------------------------------------- */

	std::deque<int>		deq;
	std::vector<int>	vec;
	unsigned int		temp;
	unsigned			num_elem;
	std::size_t			found;

	num_elem = 0;
	found = std::string(argv[1]).find(".txt");
	if (argc == 2 && found != std::string::npos)
	{
		std::ifstream	input(argv[1]);
		std::string		token;
		while (getline(input, token, ' '))
		{
			temp = isPositiveInt(token.c_str());
			deq.push_back(temp);
			vec.push_back(temp);
			num_elem += 1;
		}
	}
	else
	{
		for (int i = 1; i < argc; i += 1)
		{
			temp = isPositiveInt(argv[i]);
			deq.push_back(temp);
			vec.push_back(temp);
		}
		num_elem = argc - 1;
	}

	/* ---------------------------------------------------------------- */

	std::cout << "Before: ";
	std::deque<int>::iterator	it = deq.begin();
	for (; it != deq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	/* ---------------------------------------------------------------- */

	struct timespec	begin1, end1;
	struct timespec	begin2, end2;

	clock_gettime(CLOCK_REALTIME, &begin1);
	PmergeMe::Sort(deq);
	clock_gettime(CLOCK_REALTIME, &end1);

	clock_gettime(CLOCK_REALTIME, &begin2);
	PmergeMe::Sort(vec);
	clock_gettime(CLOCK_REALTIME, &end2);

	/* ---------------------------------------------------------------- */

	std::cout << "After: ";

	it = deq.begin();
	for (; it != deq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	/* ---------------------------------------------------------------- */

	std::cout << "Time to process a range of " << num_elem << " elements with std::deque :  "
	<< timeDiff(begin1, end1) << " us" << std::endl;

	std::cout << "Time to process a range of " << num_elem << " elements with std::vector : "
	<< timeDiff(begin2, end2) << " us" << std::endl;

	return (0);
}
