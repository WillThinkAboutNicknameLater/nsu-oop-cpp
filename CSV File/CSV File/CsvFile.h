#pragma once

#include <string>
#include <map>
#include <fstream>

class TCsvFile {
	public: 

		TCsvFile();

		~TCsvFile();

		void addSourceFile(const std::string& filePath);

		void addCsvFile(const std::string& filePath);

		void makeFormating();

	private:

		std::ifstream _sourceFile;
		std::ofstream _csvFile;
		std::map<std::string, size_t> _wordMap;
		size_t _wordCount;

		void _makeMap();
		std::multimap<size_t, std::string> _sortMapByValue();

};
