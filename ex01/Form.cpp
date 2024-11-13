#include "Form.hpp"

#include <iomanip>

#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name),
	  _signed(false),
	  _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < TOP_GRADE || _gradeToExecute < TOP_GRADE)
		throw GradeTooHighException();
	if (_gradeToSign > BOTTOM_GRADE || _gradeToExecute > BOTTOM_GRADE)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other)
	: _name(other._name),
	  _signed(other._signed),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		return *this;
	_signed = other._signed;
	return *this;
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecte() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &rhs)
{
	os << rhs.getName() << " | is sined: " << std::setw(10) << std::left
	   << (rhs.isSigned() ? "(signed)" : "(unsigned)")
	   << " | grade to sign: " << rhs.getGradeToSign()
	   << " | grade to execute: " << rhs.getGradeToExecte();
	return os;
}
