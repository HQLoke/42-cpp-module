#include "RPN.hpp"

/*
**	Constructor, destructor, copy constructor, copy assignment operator
*/

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN&	RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}
