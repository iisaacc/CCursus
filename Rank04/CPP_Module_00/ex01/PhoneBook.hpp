#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void	Search();
	void	Add();
private:
	Contact	contacts[8];
	int		oldest;
};

#endif