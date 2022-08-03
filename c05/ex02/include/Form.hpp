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

		void			beSigned( Bureaucrat & b );
		bool			checkRequirements( Bureaucrat const & executor ) const;
		virtual bool	execute( Bureaucrat const & executor ) const = 0;
		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		class FormNotSignedException : public std::exception
		{
			public:

				virtual const char * what() const throw();
		};

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
