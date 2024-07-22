/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:49:01 by bama              #+#    #+#             */
/*   Updated: 2024/07/23 00:01:22 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : contact_total(0)
{}

PhoneBook::~PhoneBook(void)
{}

void PhoneBook::Add(const Contact &contact)
{
	int	i = (this->contact_total++);

	if (i >= 8)
		i %= 8;
	this->contacts[i] = contact;
}

std::string formatString(const std::string& str)
{
	std::size_t	len;

	len = str.length();
    if (len > 10)
	{
        std::string formattedStr = str.substr(0, 10);
        formattedStr.append(str.length() - 10, '.');
        return (formattedStr);
    }
    return (str);
}

void	PhoneBook::ShowContact(const Contact &contact, int i)
{
	std::string	get;

	std::cout << "Index: " << i << std::endl;
	std::cout << "Prénom: " << formatString(contact.GetFirstName()) << "|";
	std::cout << "Nom: " << formatString(contact.GetLastName()) << "|";
	std::cout << "Surnom: " << formatString(contact.GetNickName()) << "|";
	std::cout << "Numéro: " << formatString(contact.GetPhoneNumber()) << "|";
	std::cout << "Secret sombre: " << formatString(contact.GetDarkestSecret()) << "|";
}

bool	PhoneBook::Search(int index)
{
	if (index >= contact_total || index < 0)
		return (false);
	this->ShowContact(this->contacts[index], index);
	return (true);
}
