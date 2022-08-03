#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("ShrubberyCreationForm", false, 145, 137)
{
	this->_target = "DEFAULT_TARGET";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
: Form("ShrubberyCreationForm", false, 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/



/*
** --------------------------------- METHODS ----------------------------------
*/

static const char *createTrees(void)
{
	return
	"	          .     .  .      +     .      .          .\n"
	"     .       .      .     #       .           .\n"
	"        .      .         ###            .      .      .\n"
	"      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
	"          .      . \"####\"###\"####\"  .\n"
	"       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
	"  .             \"#########\"#########\"        .        .\n"
	"        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
	"     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
	"                .\"##\"#####\"#####\"##\"           .      .\n"
	"    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
	"      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
	"    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
	"            .     \"      000      \"    .     .\n"
	"       .         .   .   000     .        .       .\n"
	".. .. ..................O000O........................ ......";
}

bool	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	bool ret;

	ret = Form::checkRequirements(executor);
	if (ret == true)
	{
		std::string		filename(this->_target + "_shrubbery");
		std::ofstream 	outfile(filename);
		outfile << createTrees();
		outfile.close();
		std::cout << "Filename: <" << filename << "> has been created with "
		"ASCII trees inside it\n";
	}
	return (ret);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
