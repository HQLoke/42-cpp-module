/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:05:27 by hloke             #+#    #+#             */
/*   Updated: 2022/07/08 16:16:13 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

/*
 * Object of class Zombie is created in the stack memory.
 * All memory allocated is destroyed after return.
 * Destructor will be called when exiting the function scope.
 */
void	randomChump(std::string name)
{
	Zombie biter(name);
	biter.announce();
}
