#include "RPN.hpp"

RPN::RPN(const std::string equation)
{
	this->_equation = equation;
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
	this->_equation = other._equation;
}

RPN&	RPN::operator=(const RPN &other)
{
	this->_equation = other._equation;
	return (*this);
}

bool	isDigit(const std::string digit)
{
	const char	*digit_str = digit.c_str();
	const int	digit_len = digit.length();
	int			i;

	i = 0;
	if (digit_str[i] == '-')
	{
		i += 1;
		if (digit_len == 1)
			return (false);
	}
	while (i < digit_len)
	{
		if (digit_str[i] >= '0' && digit_str[i] <= '9')
			i += 1;
		else
			return (false);
	}
	return (true);
}

bool	isOperator(const std::string token)
{
	const char	*oper = "+-/*";

	if (token.length() != 1)
		return (false);
	for (int i = 0; i < 4; i += 1)
	{
		if (token.find(oper[i]) != std::string::npos)
			return (true);
	}
	return (false);
}

double	doArithmetic(double first, double second, const std::string token)
{
	if (token == "+")
		return (first + second);
	else if (token == "-")
		return (first - second);
	else if (token == "/")
		return (first / second);
	else if (token == "*")
		return (first * second);
	return (INT_MAX);
}

void	RPN::Calculate()
{
	std::stack<double>	stack;
	std::stringstream	eq(_equation);
	std::string			token;
	double				tmp1, tmp2;

	while (std::getline(eq, token, ' '))
	{
		if (isDigit(token) == true)
			stack.push(std::stod(token));
		else if (isOperator(token) == true && stack.size() >= 2)
		{
			tmp2 = stack.top();
			stack.pop();
			tmp1 = stack.top();
			stack.pop();
			stack.push(doArithmetic(tmp1, tmp2, token));
		}
		else
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}

	if (stack.size() != 1)
		std::cout << "Error" << std::endl;
	else
		std::cout << stack.top() << std::endl;
}
