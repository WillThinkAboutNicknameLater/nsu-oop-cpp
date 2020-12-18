#include <string>

#include "TDefine.h"
#include "TOperationMaker.h"
#include "TErrorHandler.h"

REGISTER_OPERATION(TDefine, "DEFINE");

void TDefine::execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) {
	if (executionArguments.size() != 2) {
		throw TWrongNumberOfArguments();
	}

	std::string variableName{ executionArguments.front() };
	double variableValue{ 0 };

	try {
		variableValue = std::stod(executionArguments.back());
	} catch (...) {
		throw TWrongDataType();
	}

	executionCalculatorContext.addVariable(variableName, variableValue);
}