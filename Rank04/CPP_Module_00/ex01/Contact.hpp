#ifndef CONTACT_HPP

# define CONTACT_HPP
# include <string>
# include <iostream>

class Contact {
	public:
		Contact(void);
		~Contact(void);
		//Getters
		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nick(void) const;
		std::string	get_secret(void) const;
		std::string	get_number(void) const;
		//Setters
		void	set_fname(std::string str);
		void	set_lname(std::string str);
		void	set_nick(std::string str);
		void	set_secret(std::string str);
		void	set_number(std::string str);
		//Métodos
		void	contact_print();
		void	field_print(std::string str);
	private:
		std::string	Fname;
		std::string	Lname;
		std::string	nick;
		std::string	secret;
		std::string	number;
};

#endif