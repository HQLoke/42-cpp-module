#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat( int grade, std::string const name )
: _grade(grade), _name(name)
{
	
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	this->setGrade(src.getGrade());
	this->setName(src.getName());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->setGrade(rhs.getGrade());
		this->setName(rhs.getName());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".\n";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Bureaucrat::gradeIncrement()
{

}

void				Bureaucrat::gradeDecrement()
{

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int					Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string	const	Bureaucrat::getName	() const
{
	return (this->_name);
}

void				Bureaucrat::setGrade( int grade )
{
	this->_grade = grade;
}

void				Bureaucrat::setName	( std::string const name )
{
	this->_name = name;
}

/* ************************************************************************** */
