#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

class NoOccurrenceException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "No occurrence is found";
		}
};

#endif
