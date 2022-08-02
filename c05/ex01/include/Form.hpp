#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form();
		Form( std::string name, bool isSigned, int gradeToSign, int gradeToExecute );
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		void		beSigned( Bureaucrat & b );
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		class GradeTooHighException : public std::exception
		{
			public:

				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char * what() const throw();
		};

	private:
		
		const std::string	_name;
		bool		 		_isSigned;
		const int		 	_gradeToSign;
		const int		 	_gradeToExecute;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */
