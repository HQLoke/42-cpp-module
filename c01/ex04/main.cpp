/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:50:34 by hloke             #+#    #+#             */
/*   Updated: 2022/07/12 12:46:21 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static void	replacing(char **av, std::ifstream &infile, std::ofstream &outfile)
{
	std::string		content;
	std::string		s1(av[2]);
	std::string		s2(av[3]);
	size_t			found;
	size_t			index;

	index = 0;
	while (std::getline(infile, content))
	{
		while ((found = content.find(s1, index)) != std::string::npos)
		{
			content.erase(found, s1.length());
			content.insert(found, s2);
			index = found + s2.length();
		} 
		outfile << content << std::endl;
	}
}

int main(int ac, char **av)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	
	if (ac != 4)
	{
		std::cerr << "The program opens the file <filename> and copies its "
		          << "content into a newfile, replacing every occurrence of "
				  << "s1 with s2.\n";
		std::cerr << "Usage: ./replace filename s1 s2\n";
		exit (EXIT_FAILURE);
	}
	infile.open(av[1], std::ios::in);
	if (infile.is_open() == false)
	{
		std::cerr << "Error: file <" << av[1] << "> does not exist.\n";
		exit (EXIT_FAILURE);
	}
	else
		outfile.open(std::string(av[1]).append(".replace"), std::ios::out);
	replacing(av, infile, outfile);
	infile.close();
	outfile.close();
	return (0);
}
