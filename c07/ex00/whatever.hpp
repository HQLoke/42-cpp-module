#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b)
{
	T result;

	result = a < b ? a : b;
	return (result);
}

template <typename T>
T max(T a, T b)
{
	T result;

	result = a > b ? a : b;
	return (result);
}

#endif
