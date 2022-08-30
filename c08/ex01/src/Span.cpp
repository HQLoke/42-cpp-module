#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
	this->_maxSize = 0;
	this->_size = 0;
}

Span::Span( unsigned int maxSize )
{
	this->_maxSize = maxSize;
	this->_size = 0;
}

Span::Span( const Span & src )
{
	this->_maxSize = src._maxSize;
	this->_size = src._size;
	this->_vec = src._vec;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_maxSize = rhs._maxSize;
		this->_size = rhs._size;
		this->_vec = rhs._vec;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber( int val )
{
	if (this->_size >= this->_maxSize)
		throw Span::SizeLimitException();
	this->_vec.push_back(val);
	this->_size += 1;
}

bool	Span::hasDuplicates() const
{
	std::vector<int>	copyVec;
	bool				ret;

	copyVec = this->_vec;
	std::sort(copyVec.begin(), copyVec.end());
	ret = std::adjacent_find(copyVec.begin(), copyVec.end()) != copyVec.end();
	return (ret);
}

int		Span::longestSpan() const
{
	int	min;
	int	max;

	if (this->_size <= 1)
		throw Span::NoSpanException();
	min = *std::min_element(this->_vec.begin(), this->_vec.end());
	max = *std::max_element(this->_vec.begin(), this->_vec.end());
	return (max - min);
}

int		Span::shortestSpan() const
{
	int							diff;
	std::vector<int>			copyVec;
	std::vector<int>::iterator	ite;

	if (this->_size <= 1)
		throw Span::NoSpanException();
	diff = INT_MAX;
	copyVec = this->_vec;
	std::sort(copyVec.begin(), copyVec.end());
	for (ite = copyVec.begin(); ite != copyVec.end() - 1; ite += 1)
		diff = std::min(*(ite + 1) - *ite, diff);
	return (diff);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int		Span::getMaxSize() const
{
	return (this->_maxSize);
}

unsigned int		Span::getSize() const
{
	return (this->_size);
}

/* ************************************************************************** */

const char *Span::NoSpanException::what() const throw()
{
	return "No span can be found";
}

const char *Span::SizeLimitException::what() const throw()
{
	return "Size limit has been exceeded";
}
