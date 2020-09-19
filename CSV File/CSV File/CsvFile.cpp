#include "CsvFile.h"

#include <map>

bool IsLetter(char character) {
	return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z');
}

TCsvFile::TCsvFile() {
	_wordCount = 0;
}

TCsvFile::~TCsvFile() {
	_sourceFile.close();
	_csvFile.close();
}

void TCsvFile::addSourceFile(const std::string& filePath) {
	_sourceFile.open(filePath);

	if (!_sourceFile.is_open()) {
		throw std::exception("Could not open file!");
	}
}

void TCsvFile::addCsvFile(const std::string& filePath) {
	_csvFile.open(filePath);
	
	if (!_csvFile.is_open()) {
		throw std::exception("Could not open file!");
	}
}

void TCsvFile::makeFormating() {
	_makeMap();

	std::multimap<size_t, std::string> sortedWordMap = _sortMapByValue();

	_csvFile << "Word" << ',' << "Frequency" << ',' << "Percentage" << std::endl << std::endl;

	for (auto key = sortedWordMap.rbegin(); key != sortedWordMap.rend(); ++key) {
		double wordFrequency = (double)((*key).first) / (double)(_wordCount);
		_csvFile << (*key).second << ',' << (*key).first << ',' << wordFrequency * 100 << " %" << std::endl;
	}
}

void TCsvFile::_makeMap() {
	std::string word = { 0 };

	while (_sourceFile >> word) {
		while (!word.empty() && !IsLetter(word.back())) {
			word.pop_back();
		}
		++_wordMap[word];
		++_wordCount;
	}
}

std::multimap<size_t, std::string> TCsvFile::_sortMapByValue() {
	std::multimap<size_t, std::string> sortedWordMap;

	for (auto key = _wordMap.begin(); key != _wordMap.end(); ++key) {
		sortedWordMap.insert(std::pair<size_t, std::string>((*key).second, (*key).first));
	}

	return sortedWordMap;
}
