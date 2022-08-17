#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <iostream>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		bool	execute( Bureaucrat const & executor ) const;

	private:
		std::string		_target;
};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */
