#include "CsvFile.h"

#include <iomanip> 
#include <map>

bool IsLetter(char character) {
	return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || 
		(character >= 'À' && character <= 'ß') || (character >= 'à' && character <= 'ÿ');
}

TCsvFile::TCsvFile() {
	_wordCount = 0;
}

TCsvFile::~TCsvFile() {
	_sourceFile.close();
	_csvFile.close();
}

void TCsvFile::addFile(const std::string& fileName) {
	_sourceFile.open(fileName + ".txt");

	if (!_sourceFile.is_open()) {
		throw "Could not open file!";
	}

	_csvFile.open(fileName + " (CSV).txt");
}

void TCsvFile::makeFormating() {
	makeMap();

	std::multimap<size_t, std::string> sortedWordMap = sortMap();

	_csvFile << std::setw(30) << "Word" << std::setw(30) << "Frequency" << std::setw(32) << "Percentage" << std::endl << std::endl;

	for (auto key = sortedWordMap.rbegin(); key != sortedWordMap.rend(); ++key) {
		double wordFrequency = (double)((*key).first) / (double)(_wordCount);
		_csvFile << std::setw(30) << (*key).second << std::setw(30) << (*key).first << std::setw(30) << wordFrequency * 100 << " %" << std::endl;
	}
}

void TCsvFile::makeMap() {
	std::string word = { 0 };

	while (_sourceFile >> word) {
		while (!IsLetter(word.back())) {
			word.pop_back();
		}
		++_wordMap[word];
		++_wordCount;
	}
}

std::multimap<size_t, std::string> TCsvFile::sortMap() {
	std::multimap<size_t, std::string> sortedWordMap;

	for (auto key = _wordMap.begin(); key != _wordMap.end(); ++key) {
		sortedWordMap.insert(std::pair<size_t, std::string>((*key).second, (*key).first));
	}

	return sortedWordMap;
}
