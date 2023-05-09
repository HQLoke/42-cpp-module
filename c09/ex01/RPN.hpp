#ifndef	RPN_HPP
#define RPN_HPP

#include <climits>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class	RPN
{
	public:
		RPN(const std::string equation);
		virtual ~RPN();
		RPN(const RPN &other);
		RPN&	operator=(const RPN &other);

		void	Calculate();

	private:
		std::string	_equation;
};

#endif
