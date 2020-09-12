#pragma once

#include <string>
#include <map>
#include <fstream>

enum class FileFormat {
	SOURCE,
	CSV
};

class TCsvFile {
	public: 

		TCsvFile();

		~TCsvFile();

		void addFile(FileFormat fileFormat, const std::string& filePath);

		void makeFormating();

	private:

		std::ifstream _sourceFile;
		std::ofstream _csvFile;
		std::map<std::string, size_t> _wordMap;
		size_t _wordCount;

		void _makeMap();
		std::multimap<size_t, std::string> _sortMapByValue();

};
