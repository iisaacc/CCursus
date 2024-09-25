#pragma once

#include <string>
#include <iostream>

class Bureaucrat {
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);

		std::string	getName() const;
		int			getGrade() const;
		int			incrementGrade(int amount);
		int			decrementGrade(int amount);

	class GradeTooHighException: public std::exception {
		public:
			virtual char const	*what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			virtual char const	*what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
