#include "Account.hpp"

//Constructor
Account::Account() : _amount(0), _nbDeposits(0) , _nbWithdrawals(0) {
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created";
	_nbAccounts++;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_amount += initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
//Destructor
Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

//Métodos static
int	Account::getNbAccounts() {
	return _nbAccounts;
}

int	Account::getTotalAmount() {
	return _totalAmount;
}

int	Account::getNbDeposits() {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void	Account::_displayTimestamp() {
	std::time_t u_time = std::time(NULL);
	std::tm *time = std::localtime(&u_time);
	std::cout << "[";
	std::cout << std::setfill('0') << std::setw(4) << (time->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_mday);
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_hour);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_min);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_sec);
	std::cout << "]";
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
//Métodos
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount +=deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount(void) const {
	return (_amount);
}


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
