#include <iostream>
#include <fstream>

#include "TuplePrinter.h"
#include "CSVParser.h"
#include "ErrorHandler.h"

int main() {
	std::ifstream file{ "test.csv" };
	if (file.fail()) {
		std::cout << "The file could not be opened." << std::endl;
		return 0;
	}

	CSVParser<int, std::string> parser{ file, 1 };
	try {
		for (auto tuple : parser) {
			std::cout << tuple << std::endl;
		}
	} catch (ErrorHandler& e) {
		std::cout << e.what() << std::endl;
	}

	file.close();
	return 0;
}