#include "PmergeMe.hpp"

template void PmergeMe::Sort(std::deque<int>& container);
template void PmergeMe::Sort(std::vector<int>& container);

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	return (*this);
}

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
void	mergeSort(T& container, int left, int right)
{
	if (left < right)
	{
		int	mid = (left + right) / 2;
		mergeSort(container, left, mid);
		mergeSort(container, mid + 1, right);
		merge(container, left, mid, right);
	}
}

template<typename T>
void	PmergeMe::Sort(T& container)
{
	int	size;

	size = container.size();
	mergeSort(container, 0, size - 1);
}
