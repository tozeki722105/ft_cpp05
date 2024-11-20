#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << std::endl;

	Intern intern;
	AForm *pf = intern.makeForm("robotomy request", "Bender");
	if (pf) {
		std::cout << *pf << std::endl;
		delete pf;
	}
	std::cout << std::endl;

	pf = intern.makeForm("presidential pardon", "Ford Prefect");
	if (pf) {
		std::cout << *pf << std::endl;
		delete pf;
	}
	std::cout << std::endl;

	pf = intern.makeForm("shrubbery creation", "home");
	if (pf) {
		std::cout << *pf << std::endl;
		delete pf;
	}
	std::cout << std::endl;

	pf = intern.makeForm("unknown form", "target");
	if (pf) {
		std::cout << *pf << std::endl;
		delete pf;
	}
	std::cout << std::endl;
}