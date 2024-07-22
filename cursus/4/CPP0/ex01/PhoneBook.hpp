/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:48:03 by bama              #+#    #+#             */
/*   Updated: 2024/07/22 01:22:11 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BACK_HPP
#define PHONE_BACK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void	Add(const Contact &contact);
	void	ShowContact(const Contact &contact, int i);
	bool	Search(int index);
private:
	Contact	contacts[8];
	int		contact_total;
};


#endif