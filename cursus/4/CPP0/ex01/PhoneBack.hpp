/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBack.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:48:03 by bama              #+#    #+#             */
/*   Updated: 2024/07/15 22:59:34 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BACK_HPP
#define PHONE_BACK_HPP

# include "Contact.hpp"

class PhoneBack final
{
public:
	PhoneBack();
	~PhoneBack();

	void	Add(Contact contact);
	bool	Search(const Contact &contact);
private:
	Contact	contacts[8];
	int		contact_total;
};


#endif