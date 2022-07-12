/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:50:52 by hloke             #+#    #+#             */
/*   Updated: 2022/07/12 09:52:25 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _rWeapon(weapon)
{
}

HumanA::~HumanA(){}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _rWeapon.getType()
		      << std::endl;
}
