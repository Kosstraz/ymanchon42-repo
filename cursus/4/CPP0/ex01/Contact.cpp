/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:48:59 by bama              #+#    #+#             */
/*   Updated: 2024/07/22 01:11:06 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->firstName.clear();
	this->lastName.clear();
	this->nickName.clear();
	this->phoneNumber.clear();
	this->darkestSecret.clear();
}

Contact::~Contact(void)
{}

std::string	Contact::GetFirstName(void) const
{
	return (this->firstName);
}

std::string	Contact::GetLastName(void) const
{
	return (this->lastName);
}

std::string	Contact::GetNickName(void) const
{
	return (this->nickName);
}

std::string	Contact::GetPhoneNumber(void) const
{
	return (this->phoneNumber);
}

std::string	Contact::GetDarkestSecret(void) const
{
	return (this->darkestSecret);
}

void	Contact::SetFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void	Contact::SetLastName(std::string lastName)
{
	this->lastName = lastName;
}

void	Contact::SetNickName(std::string nickName)
{
	this->nickName = nickName;
}

void	Contact::SetPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::SetDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

void	Contact::operator=(const Contact &contact)
{
	this->firstName = contact.firstName;
	this->lastName = contact.lastName;
	this->nickName = contact.nickName;
	this->phoneNumber = contact.phoneNumber;
	this->darkestSecret = contact.darkestSecret;
}