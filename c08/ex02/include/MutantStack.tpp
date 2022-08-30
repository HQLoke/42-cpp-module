#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

/*
 * https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators#:~:text=Stack%20does%20not%20have%20iterators,std%3A%3Avector%2C%20etc).
 * https://stackoverflow.com/questions/26667991/c-error-no-type-named-iterator-in-ecd-new-to-iterators
 * https://stackoverflow.com/questions/1600936/officially-what-is-typename-for
 */
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		MutantStack( MutantStack const & src );
		~MutantStack(){};
		MutantStack &		operator=( MutantStack const & rhs );

		typedef typename std::deque<T>::iterator iterator;
		iterator begin()
		{
			return std::begin(this->c);
		}

		iterator end()
		{
			return std::end(this->c);
		}

	private:

};

#endif
