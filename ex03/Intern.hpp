#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();

	AForm *makeForm(const std::string &name, const std::string &target);

private:
	AForm *createRobotomyRequestForm(const std::string &target);
	AForm *createShrubberyCreationForm(const std::string &target);
	AForm *createPresidentialPardonForm(const std::string &target);

	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
};

#endif