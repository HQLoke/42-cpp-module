/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:09:04 by hloke             #+#    #+#             */
/*   Updated: 2022/07/06 14:08:34 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

void	ft_putstr_upper(char *str)
{
	for (size_t i = 0; i < std::strlen(str); i += 1)
		std::putchar(std::toupper(str[i]));
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"; 
		return (0);
	}
	for (int i = 1; i < ac; i += 1)
		ft_putstr_upper(av[i]);
	std::cout << "\n";
}
