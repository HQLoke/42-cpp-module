#ifndef ARRAY_TPP
# define ARRAY_TPP

/*
 * Constructors & Destructors
 */

template <typename T>
Array<T>::Array() : _size(0)
{
	this->_storage = NULL;
}

template <typename T>
Array<T>::Array( unsigned int n ) : _size(n)
{
	this->_storage = new T [this->_size];
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_storage;
}

/*
 * Copy constructor & Copy assignment operator
 */ 

template <typename T>
Array<T>::Array( Array const & src )
{
	this->_size = src.size();
	this->_storage = new T [this->_size];
	for (int i = 0; i < this->_size; i += 1)
	{
		this->_storage[i] = src[i];
	}
}

template <typename T>
Array<T> &		Array<T>::operator=( Array const & rhs )
{
	if (this != &rhs)
	{
		this->_size = rhs.size();
		if (this->_storage != NULL)
			delete [] this->_storage;
		this->_storage = new T [this->_size];
		for (int i = 0; i < this->_size; i += 1)
		{
			this->_storage[i] = rhs[i];
		}
	}
	return (*this);
}

/*
 * Operator overloading
 */

template <typename T>
T &		Array<T>::operator[](int i) const
{
	if (i < 0 || i >= this->_size)
		throw Array::OutOfBoundException();
	else
		return (this->_storage[i]);
}

template <typename T>
std::ostream &		operator<<( std::ostream & o, Array<T> const & i)
{
	o << "Size is " << i.size() << std::endl;
	for (int j = 0; j < i.size(); j += 1)
	{
		o << i[j] << " ";
	}
	return (o);
}

/*
 * Class methods
 */

template <typename T>
int		Array<T>::size() const
{
	return (this->_size);
}

/*
 * Exception handling
 */ 

template <typename T>
const char *Array<T>::OutOfBoundException::what() const throw()
{
	return "Error: accessing element outside of the boundary";
}

#endif
