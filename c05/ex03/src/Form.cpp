#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
: _name("empty_form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) 
{
}

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute)
: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->_isSigned = isSigned;
}

Form::Form( const Form & src )
: _name(src.getName()), _gradeToSign(src.getGradeToSign()),
  _gradeToExecute(src.getGradeToExecute())
{
	this->_isSigned = src.getIsSigned();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
 * Unable to change const variables. Const variables can only be set at
 * instantiation.
 */
Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form name: " << i.getName()
	  << ", Signed: " << i.getIsSigned()
	  << ", Sign grade: " << i.getGradeToSign()
	  << ", Execute grade: " << i.getGradeToExecute();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Form::beSigned( Bureaucrat & b )
{
	try
	{
		if (this->getIsSigned() == true)
		{
			throw Form::FormAlreadySignedException();
		}
		else if (b.getGrade() <= this->getGradeToSign())
		{
			this->_isSigned = true;
			std::cout << b.getName() << " signed " << this->_name << std::endl;
		}
		else
		{
			std::cout << b.getName() << " couldn't sign " << this->_name
			<< " because its above your pay grade.\n";
			throw Form::GradeTooLowException();
		}
	}
	catch ( std::exception & e )
	{
		std::cerr << e.what() << std::endl;
	}
}

bool		Form::checkRequirements( Bureaucrat const & executor ) const
{
	try
	{
		if (this->_isSigned != true)
			throw Form::FormNotSignedException();
		if (executor.getGrade() > this->_gradeToExecute)
			throw Form::GradeTooLowException();
	}
	catch ( std::exception & e )
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
	return true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Form::getName() const
{
	return this->_name;
}

bool		Form::getIsSigned() const 
{
	return this->_isSigned;
}

int			Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int			Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

/* ************************************************************************** */

const char * Form::FormAlreadySignedException::what() const throw()
{
	return "Form is signed by someone already";
}

const char * Form::FormNotSignedException::what() const throw()
{
	return "Form is not signed yet";
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
