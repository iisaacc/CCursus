#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_sign_grade;
		int const			_ex_grade;

	public:
		Form();
		Form(std::string name, int const signed_grade, int const ex_grade);
		Form(const Form  &other);
		~Form();
		Form &operator=(const Form &other);

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void		beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException: public std::exception {
		public:
			virtual char const *what(void) const throw(); //throw() al estar vacío, lo que significa es que la función promete no lanzar ninguna excepción. 
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual char const *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &obj);