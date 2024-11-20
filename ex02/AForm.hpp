#ifndef AForm_HPP
#define AForm_HPP

#include <string>

class Bureaucrat;

class AForm
{
public:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	const std::string &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &signer);
	void checkExecutable(Bureaucrat const &executor) const;
	virtual void execute(Bureaucrat const &executor) const = 0;

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
	class NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

protected:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;

private:
	AForm();
	static const int TOP_GRADE = 1;
	static const int BOTTOM_GRADE = 150;
};

std::ostream &operator<<(std::ostream &os, const AForm &rhs);

#endif