#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target, const std::string &name)
	: AForm(name, GRADE_TO_SIGN, GRADE_TO_EXECUTE), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	_target = other._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkExecutable(executor);

	static bool isFirst = true;
	if (isFirst) {
		srand((unsigned int)time(NULL));
		isFirst = false;
	}
	if (rand() % 2 == 0)
		std::cout << _target << " robotization successful." << std::endl;
	else
		std::cout << _target << " robotization failed." << std::endl;
}