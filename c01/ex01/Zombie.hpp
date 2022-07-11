/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:49:59 by hloke             #+#    #+#             */
/*   Updated: 2022/07/08 17:03:31 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void	announce();
		void	setName(std::string name);
	
	private:
		std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

# endif
