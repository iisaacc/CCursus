#include "Contact.hpp"

Contact::Contact() : Fname(""), Lname(""), nick(""), secret(""), number("") {
	}
Contact::~Contact(){
	}

//Getters
std::string	Contact::get_fname() const{
	return this->Fname;
}
std::string	Contact::get_lname() const{
	return this->Lname;
}
std::string	Contact::get_nick() const{
	return this->nick;
}
std::string	Contact::get_secret() const{
	return this->secret;
}
std::string	Contact::get_number() const{
	return this->number;
}

	//Setters
void	Contact::set_fname(std::string str){
	this->Fname = str;
}
void	Contact::set_lname(std::string str){
	this->Lname = str;
}
void	Contact::set_nick(std::string str){
	this->nick = str;
}
void	Contact::set_secret(std::string str){
	this->secret = str;
}
void	Contact::set_number(std::string str){
	this->number = str;
}

	//Métodos
void	Contact::field_print(std::string str)
{
	std::string::size_type	i = 0;
	while (i < 9 && i < str.size()){
		std::cout << str[i];
		i++;
		if (i == 8 && str.size() > 10){
			std::cout << '.';
			i++;
		}
		else if ( i == 8 && str.size() == 10){
			std::cout << str[9];
			i++;
		}
	}
	while (i < 10){
		std::cout << ' ';
		i++;
	}
	std::cout << '|';
}

void	Contact::contact_print(){
	field_print(get_fname());
	field_print(get_lname());
	field_print(get_nick());
	std::cout << std::endl;
}