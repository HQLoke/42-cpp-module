#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string	replacing(std::ifstream &infile, std::string s1, std::string s2)
{
	std::string		content;
	size_t			found;
	size_t			index;
	std::string		temp;

	index = 0;
	while (std::getline(infile, content))
	{
		while ((found = content.find(s1, index)) != std::string::npos)
		{
			content.erase(found, s1.length());
			content.insert(found, s2);
			index = found + s2.length();
		} 
		temp.append(content);
	}
	return (temp);
}

std::string	replacing_test(std::ifstream &infile, std::string s1, std::string s2)
{
	std::string		content;
	size_t			found;
	size_t			index;
	std::string		temp;

	index = 0;
	while (std::getline(infile, content))
	{
		while ((found = content.find(s1, index)) != std::string::npos)
		{
			content.replace(found, s1.length(), s2);
			index = found + s2.length();
		} 
		temp.append(content);
	}
	return (temp);
}

int main(int ac, char **av)
{
	std::ifstream	infile;
	std::ifstream	infile2;
	std::string s1[] = {" ", "bye", "h"};
	std::string s2[] = {"ZZZ", "hello", "o"};
	
	int i = 0;
	while (++i < ac)
	{
		int j = 0;
		while (j < 3)
		{
			infile.open(av[i], std::ios::in);
			std::string temp1 = replacing(infile, s1[j], s2[j]);
			infile2.open(av[i], std::ios::in);
			std::string temp2 = replacing_test(infile2, s1[j], s2[j]);

			if (temp1.compare(temp2) == 0)
			{
				std::cout << "     My version: " << temp1 << std::endl 
						  << "Replace version: " << temp2 << std::endl;
				std::cout << av[i] << ": OK!\n\n";
			}
			else
			{
				std::cout << "     My version: " << temp1 << std::endl 
						  << "Replace version: " << temp2 << std::endl;
				std::cout << av[i] << ": KO...\n\n";
			}
			
			infile.close();
			infile2.close();
			j += 1;
		}
	}
}
