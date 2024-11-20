#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string &target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	virtual void execute(Bureaucrat const &executor) const;

private:
	std::string _target;

	PresidentialPardonForm();
	static const int GRADE_TO_SIGN = 25;
	static const int GRADE_TO_EXECUTE = 5;
};

#endif