/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:49:43 by hloke             #+#    #+#             */
/*   Updated: 2022/07/11 12:02:32 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout << _name << ": NOOOO MOREEEEE braiiiiiiinnnzzzZ...\n";
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name)
{
	_name = name;
}
