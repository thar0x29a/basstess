#include <iostream>

Nec30::Nec30(Bass& self) : Architecture(self) {
  
}

auto Nec30::assemble(const string& statement) -> bool {
	std::cout << "\t" << statement << std::endl;
	return true;
}
