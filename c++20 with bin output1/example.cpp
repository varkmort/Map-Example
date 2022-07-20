#include <iostream>

#include "Init.hpp"

int main()
{
	for (auto& record : GetNames()) {
		std::cout << record << '\n';
	}
}