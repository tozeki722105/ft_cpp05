#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
public:
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	const std::string &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);

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
	Form();
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
	static const int TOP_GRADE = 1;
	static const int BOTTOM_GRADE = 150;
};

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif