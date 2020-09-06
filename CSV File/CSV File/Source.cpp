#include <iostream> 
#include <string>

#include "CsvFile.h"

void CreateCsvFile(const std::string& filePath);

int main() {
	std::string filePath = { 0 };
	std::cout << "Enter file path: ";
	std::getline(std::cin, filePath);

	CreateCsvFile(filePath);

	system("pause");
	return 0;
}

void CreateCsvFile(const std::string& filePath) {
	TCsvFile csvFile;
	csvFile.addFile(filePath);
	csvFile.makeFormating();
}