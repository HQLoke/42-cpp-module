/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:44:14 by hloke             #+#    #+#             */
/*   Updated: 2022/07/10 17:54:52 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* 
 * Array new cannot have initialization arguments.
 * Use setter function instead.
 */
Zombie *zombieHorde(int N, std::string name)
{
	Zombie	*zom;
	int		i;

	zom = new Zombie[N];
	i = -1;
	while (++i < N)
	{
		zom[i].setName(name);
	}
	return (zom);
}
