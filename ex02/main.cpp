#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << std::endl;
	// ShrubberyCreationForm test
	{
		try {
			Bureaucrat bob("Bob", 137);
			ShrubberyCreationForm shrubbery("home");
			std::cout << shrubbery << std::endl;
			bob.signForm(shrubbery);
			bob.executeForm(shrubbery);

			Bureaucrat jim("Jim", 145);
			ShrubberyCreationForm shrubbery_e("home");
			jim.signForm(shrubbery_e);
			jim.executeForm(shrubbery_e);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	// RobotomyRequestForm test
	{
		try {
			Bureaucrat bob("Bob", 45);
			RobotomyRequestForm robotomy("bender");
			std::cout << robotomy << std::endl;
			bob.signForm(robotomy);
			bob.executeForm(robotomy);

			Bureaucrat jim("Jim", 46);
			RobotomyRequestForm robotomy_e("bender");
			jim.signForm(robotomy_e);
			jim.executeForm(robotomy_e);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	// PresidentialPardonForm test
	{
		try {
			Bureaucrat bob("Bob", 5);
			PresidentialPardonForm pardon("Ford");
			std::cout << pardon << std::endl;
			bob.signForm(pardon);
			bob.executeForm(pardon);

			Bureaucrat jim("Jim", 6);
			PresidentialPardonForm pardon_e("Ford");
			jim.signForm(pardon_e);
			jim.executeForm(pardon_e);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}