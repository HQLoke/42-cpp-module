/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:20:44 by hloke             #+#    #+#             */
/*   Updated: 2022/07/08 11:07:27 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::getNbAccounts(void)
{
	return 0;
}

int Account::getTotalAmount(void)
{
	return 0;
}

int Account::getNbDeposits(void)
{
	return 0;
}

int Account::getNbWithdrawals(void)
{
	return 0;
}

void Account::displayAccountsInfos(void)
{
	
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
}

Account::~Account(){}

void Account::makeDeposit(int deposit)
{
	(void)deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	return withdrawal;
}

int	Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
	
}

void Account::_displayTimestamp(void)
{
	
}
