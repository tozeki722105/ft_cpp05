#include <iostream>
#include <stdexcept>
#include <string>

void func1()
{
	throw std::string("String exception");
}

void func2()
{
	try {
		func1();
	} catch (int e) {  // 一致しない
		std::cerr << "Caught int: " << e << std::endl;
		// throw; // 再スローすることで上位レイヤーでキャッチ可能になる
	}
	// catch (...) {
	// 	std::cout << "Catch ... throw" << std::endl;
	// 	throw;
	// }
	std::cout << "Catch外に到達" << std::endl;
	throw;
}

int main()
{
	try {
		func2();
	} catch (const std::string& e) {
		std::cerr << "Caught string: " << e << std::endl;  // ここでキャッチされる
	} catch (...) {
		std::cerr << "Caught something else" << std::endl;
	}

	return 0;
}