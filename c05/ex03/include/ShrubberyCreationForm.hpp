#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include <iostream>
# include <string>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		bool	execute( Bureaucrat const & executor ) const;

	private:

		std::string		_target;

};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */
