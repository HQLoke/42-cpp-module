#include "PmergeMe.hpp"

#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <time.h>

template<typename T>
void	merge(T& container, int left, int mid, int right)
{
	int	n1 = mid - left + 1;
	int n2 = right - mid;

	int	left_arr[n1], right_arr[n2];

	for (int i = 0; i < n1; i += 1)
		left_arr[i] = container[left + i];
	for (int i = 0; i < n2; i += 1)
		right_arr[i] = container[mid + 1 + i];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (left_arr[i] <= right_arr[j])
		{
			container[k] = left_arr[i];
			i += 1;
		}
		else
		{
			container[k] = right_arr[j];
			j += 1;
		}
		k += 1;
	}

	while (i < n1)
	{
		container[k] = left_arr[i];
		i += 1;
		k += 1;
	}

	while (j < n2)
	{
		container[k] = right_arr[j];
		j += 1;
		k += 1;
	}
}

template<typename T>
void	merge_sort(T& container, int left, int right)
{
	if (left < right)
	{
		int	mid = (left + right) / 2;
		merge_sort(container, left, mid);
		merge_sort(container, mid + 1, right);
		merge(container, left, mid, right);
	}
}

double	time_diff(const struct timespec &begin, const struct timespec &end)
{
	long	seconds;
	long	nanoseconds;
	double	elapsed;

	seconds = end.tv_sec - begin.tv_sec;
	nanoseconds = end.tv_nsec - begin.tv_nsec;
	elapsed = seconds * 1e9 + nanoseconds;
	return (elapsed * 1e-3);
}

bool	verify_input(const char *token)
{
	for (size_t i = 0; i < strlen(token); i +=1)
	{
		if (isdigit(token[i]) == false)
		{
			if (i == 0 && token[i] == '-')
				throw ("Error: negative value is not allowed.");
			else
				throw ("Error: forbidden character found.");
		}
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "No elements are given as input." << std::endl;
		return (1);
	}

	/* ---------------------------------------------------------------- */

	std::deque<int>				deq;
	std::vector<int>			vec;
	std::deque<int>::iterator	it;

	try
	{
		for (int i = 1; i < argc; i += 1)
		{
			if (verify_input(argv[i]) == true)
			{
				deq.push_back(atoi(argv[i]));
				vec.push_back(atoi(argv[i]));
			}
		}
	}
	catch (const char *err)
	{
		std::cout << err << std::endl;
		exit (1);
	}

	/* ---------------------------------------------------------------- */

	std::cout << "Before: ";
	for (it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	/* ---------------------------------------------------------------- */

	struct timespec	begin1, end1;
	struct timespec	begin2, end2;

	clock_gettime(CLOCK_REALTIME, &begin1);
	merge_sort(deq, 0, deq.size() - 1);
	clock_gettime(CLOCK_REALTIME, &end1);

	clock_gettime(CLOCK_REALTIME, &begin2);
	merge_sort(vec, 0, vec.size() - 1);
	clock_gettime(CLOCK_REALTIME, &end2);

	/* ---------------------------------------------------------------- */

	std::cout << "After: ";
	for (it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	/* ---------------------------------------------------------------- */

	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque :  "
	<< time_diff(begin1, end1) << " us" << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
	<< time_diff(begin2, end2) << " us" << std::endl;

	return (0);
}
