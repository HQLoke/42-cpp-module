/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:30:12 by hloke             #+#    #+#             */
/*   Updated: 2022/07/12 12:03:44 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harl [DEBUG/ERROR/INFO/WARNING]\n";
		exit (EXIT_FAILURE);
	}
	Harl idiot;
	idiot.complain(av[1]);
	return (0);
}
