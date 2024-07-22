/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:26:58 by bama              #+#    #+#             */
/*   Updated: 2024/07/22 01:23:43 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "includes.h"

bool	write_informations(Contact &contact)
{
	std::string	input;

	std::cout << "Saisissez un prénom\n";
	std::cin >> input;
	if (input.empty() || !input.compare(""))
		return (false);
	contact.SetFirstName(input);

	std::cout << "Saisissez un nom\n";
	std::cin >> input;
	if (input.empty() || !input.compare(""))
		return (false);
	contact.SetLastName(input);

	std::cout << "Saisissez un surnom\n";
	std::cin >> input;
	if (input.empty() || !input.compare(""))
		return (false);
	contact.SetNickName(input);

	std::cout << "Saisissez un numéro de téléphone\n";
	std::cin >> input;
	if (input.empty() || !input.compare(""))
		return (false);
	contact.SetPhoneNumber(input);

	std::cout << "Saisissez un secret bre-som\n";
	std::cin >> input;
	if (input.empty() || !input.compare(""))
		return (false);
	contact.SetDarkestSecret(input);
	return (true);
}

int main(void)
{
	std::string	input;
	int			intinput;
	Contact		contactTmp;
	PhoneBook	repertoire;	

	while (1)
	{
		std::cout << "\nEntrée acceptée : 'ADD', 'SEARCH' et 'EXIT'\n";
		std::cin >> input;
		if (!input.compare("EXIT"))
			return (0);
		else if (!input.compare("SEARCH"))
		{
			std::cin >> intinput;
			if (!repertoire.Search(intinput))
				std::cout << "Soit aucun contact n'est enregistré, soit l'index est mauvais\n";
		}
		else if (!input.compare("ADD"))
		{
			if (!write_informations(contactTmp))
				std::cout << "Erreur lors de la saisie des informations :/\n";
			else
				repertoire.Add(contactTmp);
		}
	}
	return (0);
}