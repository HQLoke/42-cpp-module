#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		bool	execute( Bureaucrat const & executor ) const;

		std::string   nanidafuq()
		{
			return this->_target;
		}

	private:

		std::string		_target;

};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */
