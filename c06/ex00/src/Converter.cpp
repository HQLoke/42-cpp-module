#include "Converter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Converter::Converter( const char * stringLiteral )
: _stringLiteral(stringLiteral), _isNeg(false), _precision(0)
{
	this->_scalarType = scalarTypeFinder(this->_stringLiteral);
	if (this->_scalarType == INVALID)
		throw Converter::BadInputException(); 
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Converter::~Converter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, Converter const & i )
{
	o << "String literal is " << i.getStringLiteral() << "\n";

	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Converter::printResults()
{
	std::cout << "char: " << "\n"
			  << "int: " << "\n"
			  << "float: " << "\n"
			  << "double: " << "\n";
}

int			Converter::scalarTypeFinder(std::string str)
{
	bool			isDot;
	bool			isFloat;
	unsigned long	i;
	std::string		temp;

	temp = str;
	i = -1;
	while (i++ < temp.length())
		std::tolower(temp[i]);
	if (temp.compare("nanf") == 0)
		return (FLOAT_TYPE);
	else if (temp.compare("nan") == 0)
		return (DOUBLE_TYPE);
	if (temp.length() == 1)
	{
		if (isdigit(temp[0]) == true)
			return (INT_TYPE);
		return (CHAR_TYPE);
	}
	isFloat = false;
	if (temp.back() == 'f')
	{
		isFloat = true;
		temp.pop_back();
	}
	if ((temp[0] == '.') || (temp.back() == '.')
		|| (temp[0] == '-' && temp[1] == '.'))
		return (INVALID);
	isDot = false;
	this->_isNeg = (temp[0] == '-');
	i = -1 + this->_isNeg;
	while (++i < temp.length())
	{
		if (temp[i] == '.' && isDot == true)
			return (INVALID);
		if (temp[i] == '.')
		{
			isDot = true;
			continue;
		}
		if (isdigit(temp[i]) == false)
			return (INVALID);
		if (isDot == true)
			this->_precision += 1;
	}
	if (isDot == false)
		return (INT_TYPE);
	return (DOUBLE_TYPE - isFloat);
}

void		Converter::storeValue()
{
	switch (this->_scalarType)
	{
		case CHAR_TYPE:
			this->_charValue = this->_stringLiteral[0];
			this->_intValue = std::stoi(this->_stringLiteral);
			this->_floatValue = std::stof(this->_stringLiteral);
			this->_doubleValue = std::stod(this->_stringLiteral);
			break ;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string	Converter::getStringLiteral() const
{
	return this->_stringLiteral;
}

int					Converter::getScalarType() const
{
	return this->_scalarType;
}


/* ************************************************************************** */

const char *Converter::BadInputException::what() const throw()
{
	return "You have entered an invalid input";
}
