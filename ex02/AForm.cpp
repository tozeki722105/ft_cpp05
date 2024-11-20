#include "AForm.hpp"

#include <iomanip>

#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < TOP_GRADE || _gradeToExecute < TOP_GRADE)
		throw GradeTooHighException();
	if (_gradeToSign > BOTTOM_GRADE || _gradeToExecute > BOTTOM_GRADE)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
	: _name(other._name),
	  _signed(other._signed),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::checkExecutable(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &rhs)
{
	os << rhs.getName() << " | is sined: " << std::setw(10) << std::left
	   << (rhs.isSigned() ? "(signed)" : "(unsigned)")
	   << " | grade to sign: " << rhs.getGradeToSign()
	   << " | grade to execute: " << rhs.getGradeToExecute();
	return os;
}
