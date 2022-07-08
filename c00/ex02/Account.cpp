/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:20:44 by hloke             #+#    #+#             */
/*   Updated: 2022/07/08 13:43:08 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = getNbAccounts();
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << checkAmount() << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << checkAmount() + deposit << ";"
			  << "nb_deposits:" << _nbDeposits + 1 << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	_amount += deposit;
	_nbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << checkAmount() << ";";
	if (withdrawal > checkAmount())
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";"
			  << "amount:" << checkAmount() - withdrawal << ";"
			  << "nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t		raw_time;
	struct tm	*time_info;
	char		buffer[20];
	
	raw_time = time(0);
	time_info = localtime(&raw_time);
	strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", time_info);
	std::cout << buffer;
}
