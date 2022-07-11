/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:06:51 by hloke             #+#    #+#             */
/*   Updated: 2022/07/11 12:03:03 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *wild;

	wild = zombieHorde(10, "First horde");
	for (int i = 0; i < 10; i += 1)
	{
		wild[i].announce();
	}
	delete[] wild;

	wild = zombieHorde(10, "Second uprising");
	for (int i = 0; i < 10; i += 1)
	{
		wild[i].announce();
	}
	delete[] wild;
	return (0);
}
