#include <iostream>

#include "PparkPpark.h"

int main()
{
	auto encoded = Encode("where are you ppark ppark ii?");
	auto decoded = Decode(encoded);

	std::cout << "encoded:" << std::endl << encoded << std::endl;
	std::cout << "decoded:" << std::endl << decoded << std::endl;
}