/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:22:09 by hloke             #+#    #+#             */
/*   Updated: 2022/07/08 10:51:13 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

/*
 * Jaclyn's recommendation:
 * Change all variables to private.
 * Use setter and getter functions instead.
 * Good practice and modularised code design.
 */
class Contact
{
	public:
		Contact();
		Contact(const Contact &c1);
		~Contact();
		
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

#endif
