#pragma once

#include <iostream>

class ErrorHandler : public std::exception {
protected:
	std::string _text;
public:
	ErrorHandler(std::string text) : _text{ text } { }

	const char* what() const noexcept {
		return _text.c_str();
	}
};

class NotEnoughData final : public ErrorHandler {
public:
	NotEnoughData(size_t columnNumber) : ErrorHandler{ "Not enough data! Column: " + std::to_string(columnNumber) + ". " } { };
};

class FailedToReadData final : public ErrorHandler {
public:
	FailedToReadData(size_t columnNumber) : ErrorHandler{ "Failed to read data! Column: " + std::to_string(columnNumber) + ". " } { };
};
