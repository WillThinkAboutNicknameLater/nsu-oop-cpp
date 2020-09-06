#pragma once

#include <string>
#include <map>
#include <fstream>

class TCsvFile {
	public: 

		TCsvFile();

		~TCsvFile();

		void addFiles(const std::string& sourceFilePath, const std::string& csvFilePath);

		void makeFormating();

	private:

		std::ifstream _sourceFile;
		std::ofstream _csvFile;
		std::map<std::string, size_t> _wordMap;
		size_t _wordCount;

		void _makeMap();
		std::multimap<size_t, std::string> _sortMap();

};
