#include <iostream> 
#include <string>

#include "CsvFile.h"

void CreateCsvFile(const std::string& sourceFilePath, const std::string& csvFilePath);

int main(int argc, char* argv[]) {
	if (argc <= 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}

	std::string sourceFilePath = argv[1];
	std::string csvFilePath = argv[2];

	CreateCsvFile(sourceFilePath, csvFilePath);

	system("pause");
	return 0;
}

void CreateCsvFile(const std::string& sourceFilePath, const std::string& csvFilePath) {
	TCsvFile csvFile;
	csvFile.addSourceFile(sourceFilePath);
	csvFile.addCsvFile(csvFilePath);
	csvFile.makeFormating();
}