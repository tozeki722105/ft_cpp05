#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this == &other)
		return *this;
	return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	const size_t FORM_COUNT = 3;
	std::string names[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *(Intern::*constructors[])(const std::string &target) = {
			&Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm,
			&Intern::createShrubberyCreationForm};

	for (size_t i = 0; i < FORM_COUNT; i++) {
		if (names[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*constructors[i])(target);
		}
	}
	std::cout << "Intern cannot create " << name << std::endl;
	return NULL;
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}