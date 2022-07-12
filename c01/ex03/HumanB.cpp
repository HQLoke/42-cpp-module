/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:50:56 by hloke             #+#    #+#             */
/*   Updated: 2022/07/12 09:53:10 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	_pWeapon = NULL;
}

HumanB::~HumanB(){}

void HumanB::attack()
{
	std::cout << _name << " attacks with their " << _pWeapon->getType()
		      << std::endl;
}

/*
 * Reference variables do take up memory.
 * The pointer below is pointing to the address of the reference variable.
 */
void HumanB::setWeapon(Weapon &weapon)
{
	_pWeapon = &weapon;
}
