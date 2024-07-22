/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:19:08 by bama              #+#    #+#             */
/*   Updated: 2024/07/23 00:28:39 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_depot)
{
	this->_nbAccounts++;
	this->_accountIndex = _nbAccounts;
	this->_totalAmount = initial_depot;
	this->_amount = initial_depot;
}

Account::~Account()
{
}

void	Account::makeDeposit(int deposit)
{
	this->_totalNbDeposits++;
	this->_nbDeposits++;
	this->_totalAmount += deposit;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal <= _totalAmount)
	{
		this->_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		this->_totalNbWithdrawals++;
		this->_nbWithdrawals++;
	}
}