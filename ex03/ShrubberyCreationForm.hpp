#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	virtual void execute(Bureaucrat const &executor) const;

private:
	std::string _target;

	ShrubberyCreationForm();
	static const int GRADE_TO_SIGN = 145;
	static const int GRADE_TO_EXECUTE = 137;
};

#endif