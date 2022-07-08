/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:05:23 by hloke             #+#    #+#             */
/*   Updated: 2022/07/08 16:18:32 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

/*
 * Object of class Zombie is created in the heap memory.
 * All memory allocated is not destroyed after return.
 * Destructor will not be called when exiting the function scope.
 */
Zombie	*newZombie(std::string name)
{
	Zombie	*ret;

	ret = new Zombie(name);
	return (ret);
}
