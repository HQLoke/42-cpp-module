#include "replace.hpp"

void	ft_replace(char **av, std::ifstream &inFile, std::ofstream &outFile)
{
	std::string		content;
	std::string		s1(av[2]);
	std::string		s2(av[3]);
	size_t			found;
	size_t			index;

	while (std::getline(inFile, content))
	{
		index = 0;
		while ((found = content.find(s1, index)) != std::string::npos)
		{
			content.erase(found, s1.length());
			content.insert(found, s2);
			index = found + s2.length();
		} 
		outFile << content << std::endl;
	}
}
