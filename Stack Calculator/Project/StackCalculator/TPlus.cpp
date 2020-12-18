#include "TPlus.h"
#include "TOperationMaker.h"
#include "TErrorHandler.h"

REGISTER_OPERATION(TPlus, "+");

void TPlus::execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) {
	if (executionCalculatorContext.getStackSize() < 2) {
		throw TWrongStackSize();
	}

	executionCalculatorContext.pushStackValue(executionCalculatorContext.popStackValue() + executionCalculatorContext.popStackValue());
}
