#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	virtual void execute(Bureaucrat const &executor) const;

private:
	std::string _target;

	RobotomyRequestForm();
	static const int GRADE_TO_SIGN = 72;
	static const int GRADE_TO_EXECUTE = 45;
};

#endif