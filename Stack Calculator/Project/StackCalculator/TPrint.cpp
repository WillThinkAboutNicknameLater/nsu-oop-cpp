#include <iostream>

#include "TPrint.h"
#include "TOperationMaker.h"

REGISTER_OPERATION(TPrint, "PRINT");

void TPrint::execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) {
	std::cout << executionCalculatorContext.getStackTopValue() << std::endl;
}