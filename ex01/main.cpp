#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		std::cout << std::endl;
		Bureaucrat bob("Bob", 2);
		Form       f1("Form_1", 5, 10);
		std::cout << f1 << std::endl;
		bob.signForm(f1);
		std::cout << f1 << std::endl;
		std::cout << std::endl;

		Bureaucrat jim("Jim", 2);
		Form       f2("Form_2", 1, 10);
		std::cout << f2 << std::endl;
		jim.signForm(f2);  // Jim's grade is too low
		std::cout << f2 << std::endl;
		jim.incrementGrade();
		jim.signForm(f2);
		std::cout << f2 << std::endl;
		std::cout << std::endl;

		// Form h("Form_3", 0, 10);  // exception throw
		// Form i("Form_4", 1, 151);  // exception throw

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}