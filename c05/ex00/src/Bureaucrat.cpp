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
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
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

void				Bureaucrat::gradeIncrement( int amount )
{
	try
	{
		if (this->_grade - amount < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade -= amount;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
}

void				Bureaucrat::gradeDecrement( int amount )
{
	try
	{
		if (this->_grade + amount > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade += amount;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
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

const char *		Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *		Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
