#pragma once

#include <sstream>

#include "TupleReader.h"
#include "ErrorHandler.h"

template<typename... Args>
class CSVParser {
private:
	size_t _numberOfSkippedLines;
	std::ifstream& _file;
	char _delimiter;
	std::streampos _startingPosition;

	void skipLines() {
		for (size_t idx{ 0 }; idx < _numberOfSkippedLines; ++idx) {
			std::string skippedLine{ 0 };
			std::getline(_file, skippedLine);
		}
	}

public:
	CSVParser(std::ifstream& file, size_t numberOfSkippedLines = 0, char delimiter = ';') : _file{ file }, _numberOfSkippedLines{ numberOfSkippedLines }, _delimiter{ delimiter } {
		skipLines();
		_startingPosition = _file.tellg();
	}

	class InputIterator {
	private:
		CSVParser& _parser;
		std::tuple<Args...> _tupleItr;
		bool _isLastIterator;
		size_t _lineNumber;
		std::streampos _currentPosition;

		class OwnCType : public std::ctype<char> {
		private:
			mask _table[table_size];

		public:
			explicit OwnCType(char delimiter, size_t refs = 0) : std::ctype<char>{ &_table[0], false, refs } {
				std::copy_n(classic_table(), table_size, _table);
				_table[' '] = lower;
				_table[delimiter] = space;
			}
		};

		void readTuple() {
			if (_parser._file.eof()) {
				_isLastIterator = true;
				return;
			}
			_parser._file.clear();
			_parser._file.seekg(_currentPosition);
			std::string currentLine;
			std::getline(_parser._file, currentLine);
			_currentPosition = _parser._file.tellg();
			std::istringstream lineParser{ currentLine };
			lineParser.imbue(std::locale{ std::locale::classic(), new OwnCType{ _parser._delimiter } });
			_tupleItr = TupleReader<char, std::char_traits<char>, Args...>::read(lineParser, _lineNumber);
			++_lineNumber;
		}

	public:
		InputIterator(CSVParser& parser, bool isLastIterator) : _parser{ parser }, _isLastIterator{ isLastIterator }, _lineNumber{ parser._numberOfSkippedLines + 1 }, _currentPosition{ parser._startingPosition } {
			if (isLastIterator) {
				return;
			}
			readTuple();
		}

		~InputIterator() = default;

		bool operator!=(const InputIterator& other) const {
			return _isLastIterator != other._isLastIterator;
		}

		InputIterator& operator++() {
			readTuple();
			return *this;
		}

		std::tuple<Args...> operator*() const {
			return _tupleItr;
		}

	};

	InputIterator begin() {
		_file.clear();
		_file.seekg(_startingPosition);
		return InputIterator{ *this, false };
	}

	InputIterator end() {
		return InputIterator{ *this, true };
	}

};
