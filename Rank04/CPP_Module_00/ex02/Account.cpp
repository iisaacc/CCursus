#include "Account.hpp"
//Constructor
Account::Account() : _amount(0), _nbDeposits(0) , _nbWithdrawals(0) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(0), _nbWithdrawals(0) {
	if (initial_deposit > 0)
		_nbDeposits = 1;
	else
		_nbDeposits = 0;
	_nbAccounts++;
	_amount += initial_deposit;
}
//Destructor
Account::~Account() {
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

void	Account::displayAccountsInfos() {
	std::time_t ctime = std::time(NULL);
	std::cout << ctime;
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
//Métodos
void	Account::displayStatus( void ) const {
	std::cout << " index:" << _accountIndex << ";total:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
void	Account::makeDeposit(int deposit) {
	_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		return (true);
	}
	else
		return (false);
}

int		Account::checkAmount(void) const {
	return (_amount);
}


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;