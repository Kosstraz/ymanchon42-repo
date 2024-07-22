/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:49:01 by bama              #+#    #+#             */
/*   Updated: 2024/07/22 01:29:10 by bama             ###   ########.fr       */
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

void	PhoneBook::ShowContact(const Contact &contact, int i)
{
	std::string	get;

//std::setfill('.') << std::setw(10)
	std::cout << std::setfill('.') << std::setw(10) << "Index: " << i << std::endl;
	std::cout << "Prénom: " << contact.GetFirstName() << std::endl;
	std::cout << "Nom: " << contact.GetFirstName() << std::endl;
	std::cout << "Surnom: " << contact.GetFirstName() << std::endl;
}

bool	PhoneBook::Search(int index)
{
	if (index >= contact_total || index < 0)
		return (false);
	this->ShowContact(this->contacts[index], index);
	return (true);
}
