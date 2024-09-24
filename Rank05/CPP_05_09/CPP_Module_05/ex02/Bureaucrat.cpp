#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
	std::cout << "A noname Bureaucrat has appeared." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
	std::cout << "Bureaucrat " << name << " with grade " << grade << " created." << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " has disappeared" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name + "_copy"), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this != &other) {
	this->_grade = other._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const{
	return (this->_name);
}
int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::signForm(Form &form) {
	if (form.getSignGrade() >= this->_grade) {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because his grade isn't enough" << std::endl;
}

void	Bureaucrat::executeForm(const Form &form) const {
	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

int	Bureaucrat::incrementGrade(int amount) {
	if (this->_grade - amount < 1)
		throw (Bureaucrat::GradeTooHighException());
	else {
		std::cout << "Grade increased by " << amount << std::endl;
		this->_grade -= amount;
	}
	return (this->_grade);
}

int	Bureaucrat::decrementGrade(int amount) {
	if (this->_grade + amount > 150)
		throw (Bureaucrat::GradeTooLowException());
	else {
		std::cout << "Grade decreased by " << amount << std::endl;
		this->_grade += amount;
	}
	return (this->_grade);
}

char const *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high!");
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low!");
}

// Cuando sobrecargas un operador como un método de una clase (es decir, dentro de la clase), el primer operando
// del operador es siempre el objeto de la clase (this). Por ejemplo, si tienes una clase Foo y sobrecargas 
// el operador + dentro de Foo, entonces puedes hacer foo1 + foo2, pero no puedes hacer int + foo1.
// En el caso del operador <<, el primer operando es un flujo de salida (std::ostream), y el segundo operando es 
// el objeto que quieres imprimir. Si intentas sobrecargar << dentro de tu clase, el compilador esperará que el primer operando sea un objeto de tu clase, lo cual no es lo que quieres.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj){
	os << obj.getName() << " , with grade " << obj.getGrade();
	return (os);
};