#include "Bureaucrat.hpp"

#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (_grade < TOP_GRADE)
		throw GradeTooHighException();
	if (_grade > BOTTOM_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	_grade = other._grade;
	return *this;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == TOP_GRADE)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == BOTTOM_GRADE)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what()
				  << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what()
				  << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}
