#include "CsvFile.h"

#include <map>

bool IsLetter(char character) {
	return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || 
		(character >= 'À' && character <= 'ß') || (character >= 'à' && character <= 'ÿ');
}

bool IsDigit(char character) {
	return character >= '0' && character <= '9';
}

TCsvFile::TCsvFile() {
	_wordCount = 0;
}

TCsvFile::~TCsvFile() {
	_sourceFile.close();
	_csvFile.close();
}

void TCsvFile::addFiles(const std::string& sourceFilePath, const std::string& csvFilePath) {
	_sourceFile.open(sourceFilePath);

	if (!_sourceFile.is_open()) {
		throw "Could not open file!";
	}

	_csvFile.open(csvFilePath);
}

void TCsvFile::makeFormating() {
	_makeMap();

	std::multimap<size_t, std::string> sortedWordMap = _sortMap();

	_csvFile << "Word" << ',' << "Frequency" << ',' << "Percentage" << std::endl << std::endl;

	for (auto key = sortedWordMap.rbegin(); key != sortedWordMap.rend(); ++key) {
		double wordFrequency = (double)((*key).first) / (double)(_wordCount);
		_csvFile << (*key).second << ',' << (*key).first << ',' << wordFrequency * 100 << " %" << std::endl;
	}
}

void TCsvFile::_makeMap() {
	std::string word = { 0 };

	while (_sourceFile >> word) {
		while (!IsLetter(word.back()) && !IsDigit(word.back())) {
			word.pop_back();
		}
		++_wordMap[word];
		++_wordCount;
	}
}

std::multimap<size_t, std::string> TCsvFile::_sortMap() {
	std::multimap<size_t, std::string> sortedWordMap;

	for (auto key = _wordMap.begin(); key != _wordMap.end(); ++key) {
		sortedWordMap.insert(std::pair<size_t, std::string>((*key).second, (*key).first));
	}

	return sortedWordMap;
}
