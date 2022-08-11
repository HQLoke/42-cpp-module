#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

/*
 *	https://stackoverflow.com/questions/1600936/officially-what-is-typename-for
 *	[Typename] specifies that the identifier that follows is a type.
 *	Without typename, what follows would be considered a static member.
 */
template <typename T>
typename T::iterator	easyfind(T& container, int val)
{
	typename T::iterator	ret;
	
	ret = std::find(container.begin(), container.end(), val);
	if (ret == container.end())
		throw NoOccurrenceException();
	else
		return (ret);
}

#endif
