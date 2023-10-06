/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:04:11 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/06 22:30:42 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

/* Private methods */

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;

void	Account::_displayTimestamp(void)
{
	time_t		now = time(0);
	struct tm	*ltm = localtime(&now);

	std::cout << "[" << 1900 + ltm->tm_year;
	std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_sec;
	std::cout << "] ";
}

/* Public methods */

Account::Account(int initial_deposit)
{
	this->_accountIndex		= _nbAccounts;
	this->_amount			= initial_deposit;
	this->_nbDeposits		= 0;
	this->_nbWithdrawals	= 0;
	_nbAccounts		+= 1;
	_totalAmount	+= initial_deposit;
	_displayTimestamp();
	std::cout	<< "index:"		<< this->_accountIndex
				<< ";amount:"	<< this->_amount
				<< ";created"	
				<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index:"		<< this->_accountIndex
				<< ";amount:"	<< this->_amount
				<< ";closed"
				<< std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:"		<< _nbAccounts
				<< ";total:"		<< _totalAmount
				<< ";deposits:"		<< _totalNbDeposits
				<< ";withdrawals:"	<< _totalNbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout	<< "index:"		<< this->_accountIndex
				<< ";p_amount:"	<< this->_amount
				<< std::flush;
	this->_amount		+= deposit;
	this->_nbDeposits	+= 1;
	_totalAmount		+= deposit;
	_totalNbDeposits	+= 1;
	std::cout	<< ";deposit:"		<< deposit
				<< ";amount:"		<< this->_amount
				<< ";nb_deposits:"	<< this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout	<< "index:"		<< this->_accountIndex
				<< ";p_amount:"	<< this->_amount
				<< std::flush;
	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount			-= withdrawal;
	this->_nbWithdrawals	+= 1;
	_totalAmount			-= withdrawal;
	_totalNbWithdrawals		+= 1;
	std::cout	<< ";withdrawal:"		<< withdrawal
				<< ";amount:"			<< this->_amount
				<< ";nb_withdrawals:"	<< this->_nbWithdrawals
				<< std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:"		<< this->_accountIndex
				<< ";amount:"		<< this->_amount
				<< ";deposits:"		<< this->_nbDeposits
				<< ";withdrawals:"	<< this->_nbWithdrawals
				<< std::endl;
}
