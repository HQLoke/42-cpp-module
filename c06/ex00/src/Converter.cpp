#include "Converter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Converter::Converter( const char * stringLiteral )
: _stringLiteral(stringLiteral), _scalarType(0), _sign(1), _precision(0)
{
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

static void		_printChar(char c)
{
	std::cout << "char: ";
	if (isprint(c) == true)
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void			Converter::printResults()
{
	std::string temp;

	temp = this->_stringLiteral;
	if (temp.length() == 1 && isdigit(temp[0]) == false)
		return (_handleChar());
	_handleSign(temp);
	if (_handleSpecialCase(temp) == true)
		return ;
	if (temp.back() == 'f' || temp.back() == 'F')
	{
		this->_scalarType = FLOAT_TYPE;
		temp.pop_back();
	}
	if (_handleDot(temp) == false)
		_handleInt(temp);
	else
		_handleFloat(temp);
}

void			Converter::_handleChar()
{
	char	c;

	c = static_cast<char>(this->_stringLiteral[0]);
	this->_scalarType = CHAR_TYPE;
	_printChar(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

/*
 * Returns false if no dot is found
 */
bool			Converter::_handleDot( std::string &temp )
{
	bool	isDot;
	int		i;

	if (temp[0] == '.' || temp.back() == '.')
		throw Converter::BadInputException();
	isDot = false;
	i = -1; 
	while (++i < (int)temp.length())
	{
		if (temp[i] == '.' && isDot == true)
			throw Converter::BadInputException();
		if (temp[i] == '.')
		{
			isDot = true;
			continue ;
		}
		if (isdigit(temp[i]) == false)
			throw Converter::BadInputException();
		if (isDot == true)
			this->_precision += 1;
	}
	return (isDot);
}

void			Converter::_handleFloat( std::string &temp )
{
	double	value;

	if (this->_scalarType != FLOAT_TYPE)
		this->_scalarType = DOUBLE_TYPE;
	value = atof(temp.c_str()) * this->_sign;
	_printChar(static_cast<char>(value));
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(this->_precision);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void			Converter::_handleInt( std::string &temp )
{
	long	value;

	this->_scalarType = INT_TYPE;
	value = atol(temp.c_str()) * this->_sign;
	if (value < INT_MIN || value > INT_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		_printChar(static_cast<char>(value));
		std::cout << "int: " << value << std::endl;
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void			Converter::_handleSign( std::string &temp )
{
	if (temp[0] == '+' || temp[0] == '-')
	{
		if (temp[0] == '+')
			this->_sign = 1;
		else if (temp[0] == '-')
			this->_sign = -1;
		temp.erase(0, 1);
	}
}

bool			Converter::_handleSpecialCase( std::string &temp )
{
	const char	*special[] = {"inff", "inf", "nanf", "nan"};
	const int	size = sizeof(special) / sizeof(special[0]);
	int			i;

	this->_scalarType = INVALID;
	transform(temp.begin(), temp.end(), temp.begin(), tolower);
	i = -1;
	while (++i < size)	
		if (temp.compare(special[i]) == 0)
			break ;
	if (i == size)
		return (false);
	std::cout << "char: impossible" << std::endl; 
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	(this->_sign == 1) ? std::cout << '+' : std::cout << '-';
	std::cout << atof(special[i]) << "f" << std::endl;
	std::cout << "double: ";
	(this->_sign == 1) ? std::cout << '+' : std::cout << '-';
	std::cout << atof(special[i]) << std::endl;
	return (true);
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
