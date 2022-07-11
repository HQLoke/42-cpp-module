/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:50:34 by hloke             #+#    #+#             */
/*   Updated: 2022/07/11 22:48:52 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "The program opens the file <filename> and copies its\n"
		          << "content into a newfile, replacing every occurrence of\n"
				  << "s1 with s2.\n";
		std::cerr << "Usage: ./replace filename s1 s2\n";
		return (EXIT_FAILURE);
	}
	
	std::ifstream	infile(av[1]);
	std::ofstream	outfile(std::string(av[1]).append(".replace"), std::ios::app);
	std::string		content;

	while (std::getline(infile, content))
	{
		std::string	s1(av[2]);
		std::string	s2(av[3]);
		size_t		found;
		size_t		index = 0;
		
		do
		{
			found = content.find(s1, index);
			if (found != std::string::npos)
			{
				content.erase(found, s1.length());
				content.insert(found, s2);
			}
			index = found + s2.length();
		} while (found != std::string::npos);
		outfile << content << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}
