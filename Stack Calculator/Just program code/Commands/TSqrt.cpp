#include <cmath>

#include "TSqrt.h"
#include "TOperationMaker.h"
#include "TErrorHandler.h"

REGISTER_OPERATION(TSqrt, "SQRT");

void TSqrt::execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) {
	if (executionCalculatorContext.stackIsEmpty()) {
		throw TStackIsEmpty();
	}

	if (executionCalculatorContext.getStackTopValue() < 0) {
		throw TNegativeNumber();
	}

	executionCalculatorContext.pushStackValue(sqrt(executionCalculatorContext.popStackValue()));
}
