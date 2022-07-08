/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:06:51 by hloke             #+#    #+#             */
/*   Updated: 2022/07/08 16:21:43 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 * This exercise is about understanding heap vs stack memory.
 * The randomChump function is placed before delete to see how constructor and
 * destructor are called.
 */
int main(void)
{
	Zombie *wild;

	wild = newZombie("Heaper Jibber");
	wild->announce();
	randomChump("I'm stacked");
	delete wild;
}
