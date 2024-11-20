#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", GRADE_TO_SIGN, GRADE_TO_EXECUTE), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	_target = other._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkExecutable(executor);

	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}