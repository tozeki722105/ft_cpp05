#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", GRADE_TO_SIGN, GRADE_TO_EXECUTE), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	_target = other._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->checkExecutable(executor);

	std::ofstream ofs(_target + "_shrubbery");
	if (!ofs)
		throw std::ios_base::failure(_target + "_shrubbery");
	ofs << "       _-_\n"
		   "    /~~   ~~\\\n"
		   " /~~         ~~\\\n"
		   "{               }\n"
		   " \\  _-     -_  /\n"
		   "   ~  \\\\ //  ~\n"
		   "_- -   | | _- _\n"
		   "  _ -  | |   -_\n"
		   "      // \\\\\n";
	ofs.close();
}