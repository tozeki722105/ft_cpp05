#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat a("Bob", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		// a.incrementGrade();  // throws exception

		Bureaucrat b("Jim", 149);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		// b.decrementGrade();  // throws exception

		// Bureaucrat c("John", 151);  // throws exception

		// Bureaucrat d("John", 0);  // throws exception

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}