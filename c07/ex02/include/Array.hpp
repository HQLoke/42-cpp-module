#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{
	public:
		Array();
		Array( unsigned int n );
		Array( Array const & src );
		~Array();

		Array<T> &	operator=( Array const & rhs );
		T &			operator[](int i) const;

		int			size() const;

	private:
		int					_size;
		T *					_storage;

		class OutOfBoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>
std::ostream &			operator<<( std::ostream & o, Array<T> const & i );

#endif /* *********************************************************** ARRAY_H */
