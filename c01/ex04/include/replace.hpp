#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <fstream>
# include <iostream>
# include <sstream>
# include <string>
# include "unistd.h"

void	ft_filecheck(std::ifstream & inFile, const char * fileName);
void	ft_perror(const char * errorMsg);
void	ft_replace(char **av, std::ifstream &inFile, std::ofstream &outFile);

#endif
