#include "replace.hpp"

/*
 * Checks for three errors: file does not exist, permission denied,
 * and empty file.
 */
void	ft_filecheck(std::ifstream & inFile, const char * fileName)
{
	if (access(fileName, F_OK) == -1)
	{
		std::cerr << "File <" << fileName << "> does not exist." << std::endl;
		exit (EXIT_FAILURE);
	}
	if (access(fileName, R_OK) == -1)
	{
		std::cerr << "Permission denied. Unable to read file <" << fileName
		<< ">." << std::endl;
		exit (EXIT_FAILURE);
	}
	inFile.open(fileName, std::ios::in);
	if (inFile.peek() == EOF)
	{
		std::cerr << "File <" << fileName << "> is empty." << std::endl;
		exit (EXIT_FAILURE);
	}
}

void	ft_perror(const char * errorMsg)
{
	std::cerr << errorMsg << std::endl;
	exit (EXIT_FAILURE);
}
