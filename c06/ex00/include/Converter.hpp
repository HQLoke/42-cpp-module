#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

enum e_macro
{
	CHAR_TYPE = 1,
	INT_TYPE = 2,
	FLOAT_TYPE = 3,
	DOUBLE_TYPE = 4,
	INVALID = 5
};

class Converter
{
	public:
		Converter( const char * stringLiteral );
		~Converter();

		void				printResults();
		const std::string	getStringLiteral() const;
		int					getScalarType() const;	

	private:
		const std::string	_stringLiteral;
		int					_scalarType;
		int					_sign;
		unsigned short		_precision;

		void				_handleChar();
		bool				_handleDot( std::string &temp );
		void				_handleFloat( std::string &temp );
		void				_handleInt( std::string &temp );
		void				_handleSign( std::string &temp );
		bool				_handleSpecialCase( std::string &temp );
	
		class BadInputException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
};

std::ostream &			operator<<( std::ostream & o, Converter const & i );

#endif /* ******************************************************* CONVERTER_H */
