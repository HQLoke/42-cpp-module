/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:22:09 by hloke             #+#    #+#             */
/*   Updated: 2022/07/07 15:22:05 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:
		Contact();
		~Contact();
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif
