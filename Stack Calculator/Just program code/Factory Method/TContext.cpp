#include "TContext.h"
#include "TErrorHandler.h"

bool TContext::stackIsEmpty() const {
	return _stack.empty();
}

void TContext::pushStackValue(double number) {
	_stack.push(number);
}

double TContext::popStackValue() {
	if (_stack.empty()) {
		throw TStackIsEmpty();
	}

	double topValue{ _stack.top() };
	_stack.pop();

	return topValue;
}

size_t TContext::getStackSize() const {
	return _stack.size();
}

double TContext::getStackTopValue() const {
	if (_stack.empty()) {
		throw TStackIsEmpty();
	}

	return _stack.top();
}

void TContext::addVariable(std::string& name, double value) {
	_variables[name] = value;
}

double TContext::getValueOfVariable(std::string& name) const {
	if (_variables.find(name) == _variables.end()) {
		throw TVariableDoesNotExist();
	}

	return _variables.at(name);
}
