#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form) const;
	void executeForm(AForm const &form) const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	Bureaucrat();
	const std::string _name;
	int _grade;
	static const int TOP_GRADE = 1;
	static const int BOTTOM_GRADE = 150;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif