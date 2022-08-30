#include "Span.hpp"
#include "colour.h"

int main(void)
{
	// std::cout << "|-----------------------------------|" << std::endl;
	// std::cout << "|       Test given in the PDF       |" << std::endl;
	// std::cout << "|-----------------------------------|" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// std::cout << "|------------------------|" << std::endl;
	// std::cout << "|       Extra test       |" << std::endl;
	// std::cout << "|------------------------|" << std::endl;
	// const int	size = 10000;
	// Span		sp = Span(size);
	
	// srand(time(0));
	// for (int i = 0; i < size - 5; i += 1)
	// {
	// 	int random = rand() % 100000000;
	// 	sp.addNumber(random);
	// }

	// std::cout << std::boolalpha;
	// std::cout << "Max size: " << sp.getMaxSize() << std::endl;
	// std::cout << "Current size: " << sp.getSize() << std::endl;
	// std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	// std::cout << "Has duplicates: " << sp.hasDuplicates() << std::endl;
	// std::cout << "Shortest span: " << sp.shortestSpan() << "\n" << std::endl;

	// std::array<int, 5> arr = {100000000, 1,  1000000, 100, 10000};
	// sp.addNumber(arr.begin(), arr.end());

	// std::cout << "Max size: " << sp.getMaxSize() << std::endl;
	// std::cout << "Current size: " << sp.getSize() << std::endl;
	// std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	// std::cout << "Has duplicates: " << sp.hasDuplicates() << std::endl;
	// std::cout << "Shortest span: " << sp.shortestSpan() << "\n" << std::endl;
	return (0);
}
