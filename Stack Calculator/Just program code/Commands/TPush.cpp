#include <string>

#include "TPush.h"
#include "TOperationMaker.h"
#include "TErrorHandler.h"

REGISTER_OPERATION(TPush, "PUSH");

void TPush::execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) {
	if (executionArguments.size() != 1) {
		throw TWrongNumberOfArguments();
	}

	std::string argument{ executionArguments.front() };
	double value{ 0 };

	try {
		value = std::stod(argument);
	} catch (...) {
		value = executionCalculatorContext.getValueOfVariable(argument);
	}

	executionCalculatorContext.pushStackValue(value);
}