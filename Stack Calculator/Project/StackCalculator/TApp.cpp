#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "TApp.h"
#include "TOperation.h"
#include "TOperationFactory.h"
#include "TErrorHandler.h"

TApp::TApp(const std::string& filePath) : _filePath{ filePath } { }

void TApp::setFilePath(const std::string& filePath) {
	_filePath = filePath;
}

void TApp::run() {
	std::fstream inputFile;
	inputFile.open(_filePath);

	if (inputFile.is_open()) {
	std::cout << _filePath << std::endl;
		readData(inputFile);
	} else {
		readData(std::cin);
	}

	inputFile.close();
}

void TApp::readData(std::istream& stream) {
	std::string currentCommand{ 0 };

	while (std::getline(stream, currentCommand)) {
		std::istringstream stringParser{ currentCommand };

		std::string operation{ 0 };
		stringParser >> operation;
		if (operation == QUIT_COMMAND) {
			break;
		}
		
		std::list<std::string> arguments;
		while (!stringParser.eof()) {
			std::string currentArgument{ 0 };
			stringParser >> currentArgument;
			arguments.push_back(currentArgument);
		}

		try {
			std::unique_ptr<TOperation> currentOperation{ TOperationFactory::getInstance().createOperation(operation) };
			currentOperation->execute(arguments, _context);
		} catch (TErrorHandler& e) {
			std::cout << e.what() << std::endl;
		} 

	}
}
