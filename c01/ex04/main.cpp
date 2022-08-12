#include "replace.hpp"

/*
 * The program opens the file <filename> and copies its content into a
 * newfile, replacing every occurrence of s1 with s2.
 */
int main(int ac, char **av)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	
	if (ac != 4)
		ft_perror("Usage: ./replace filename s1 s2");
	ft_filecheck(inFile, av[1]);
	outFile.open(std::string(av[1]).append(".replace"), std::ios::out);
	ft_replace(av, inFile, outFile);
	inFile.close();
	outFile.close();
	return (0);
}
