#include "Span.hpp"
#include "colour.h"

int main(void)
{
	// std::cout << "|-----------------------------------|" << std::endl;
	// std::cout << "|       Test given in the PDF       |" << std::endl;
	// std::cout << "|-----------------------------------|" << std::endl;
	// Span sp = Span(5);

	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);

	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	Span sp = Span(100);
	std::array<int, 5> arr = {100000000, 1,  1000000, 100, 10000};
	
	sp.addNumber(arr.begin(), arr.end());

	std::cout << sp.getMaxSize() << std::endl;
	std::cout << sp.getSize() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	return (0);
}
