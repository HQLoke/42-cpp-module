#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <array>
# include <iostream>
# include <string>
# include <vector>

class Span
{
	public:
		Span();
		Span( unsigned int maxSize );
		Span( Span const & src );
		~Span();
		Span &			operator=( Span const & rhs );
		void			addNumber( int val );
		int				longestSpan() const;
		int				shortestSpan() const;
		unsigned int	getMaxSize() const;
		unsigned int	getSize() const;
		
		template <typename Iterator>
		void	addNumber(Iterator begin, Iterator end)
		{
			int	insertSize;

			insertSize = end - begin;
			if (this->_size + insertSize > this->_maxSize)
				throw Span::NoSpanException();
			this->_size += insertSize;
			this->_vec.insert(this->_vec.begin(), begin, end);
		}

	private:
		unsigned int		_maxSize;
		unsigned int		_size;
		std::vector<int>	_vec;

		class NoSpanException : public std::exception
		{
			virtual const char *what() const throw();
		};
		
		class SizeLimitException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif /* ************************************************************ SPAN_H */
