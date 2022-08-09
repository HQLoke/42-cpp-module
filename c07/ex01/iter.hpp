#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *array, size_t arraySize, void (*func)(T const &arg))
{
	for (size_t i = 0; i < arraySize; i += 1)
	{
		func(array[i]);
	}
}

template <typename T>
void	print(T const &arg)
{
	std::cout << arg << " ";
}

#endif
