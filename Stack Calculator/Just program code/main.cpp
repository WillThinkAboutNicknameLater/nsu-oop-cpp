#include <iostream>

#include "TApp.h"

int main(int argc, char** argv) {
	std::string filePath{ 0 };
	if (argc > 1) {
		filePath = argv[1];
	} else {
		std::cout << "Welcome to the calculator. Enter \"COMMANDS\" for a list of commands." << std::endl;
	}

	TApp app{ filePath };
	try {
		app.run();
	} catch(...) {
		std::cout << "Something went wrong." << std::endl;
	}

	return 0;
}