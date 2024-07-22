/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:48:46 by bama              #+#    #+#             */
/*   Updated: 2024/07/22 01:03:49 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>

class Contact
{
public:
	Contact();
	~Contact();

	std::string	GetFirstName() const;
	std::string	GetLastName() const;
	std::string	GetNickName() const;
	std::string	GetPhoneNumber() const;
	std::string	GetDarkestSecret() const;
	void		SetFirstName(std::string firstName);
	void		SetLastName(std::string lastName);
	void		SetNickName(std::string nickName);
	void		SetPhoneNumber(std::string phoneNumer);
	void		SetDarkestSecret(std::string darkestSecret);

	void		operator=(const Contact &contact);
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
};

#endif