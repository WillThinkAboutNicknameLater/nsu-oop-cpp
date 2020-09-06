#include <iostream> 
#include <string>

#include "CsvFile.h"

int main() {
	std::string filePath = { 0 };
	std::cout << "Enter file path: ";
	std::getline(std::cin, filePath);

	TCsvFile csvFile;
	csvFile.addFile(filePath);
	csvFile.makeFormating();

	system("pause");
	return 0;
}