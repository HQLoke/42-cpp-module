#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( int grade, std::string const name );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		void				gradeIncrement( int amount );
		void				gradeDecrement( int amount );
		int					getGrade() const;
		std::string	const	getName	() const;
		void				setGrade( int grade );
		void				setName	( std::string const name );

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

		int					_grade;
		std::string 		_name;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */
