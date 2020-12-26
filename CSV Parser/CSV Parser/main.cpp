#include <iostream>
#include <fstream>

#include "TuplePrinter.h"
#include "CSVParser.h"
#include "ErrorHandler.h"

int main() {
	std::ifstream file{ "Test.csv" };
	if (file.fail()) {
		std::cout << "The file could not be opened." << std::endl;
		return 0;
	}

	CSVParser<size_t, std::string, int, std::string, double> parser{ file, 3 };
	try {
		for (auto tuple : parser) {
			std::cout << tuple << std::endl;
		}
	} catch (NotEnoughData& e) {
		std::cout << e.what() << "Line: " << e.getLineNumber() << "." << std::endl;
	} catch (FailedToReadData& e) {
		std::cout << e.what() << "Line: " << e.getLineNumber() << ". Column: " << e.getColumnNumber() << "." << std::endl;
	}

	file.close();
	return 0;
}