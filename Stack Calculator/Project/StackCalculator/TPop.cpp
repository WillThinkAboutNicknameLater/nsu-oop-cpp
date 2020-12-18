#include "TPop.h"
#include "TOperationMaker.h"

REGISTER_OPERATION(TPop, "POP");

void TPop::execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) {
	executionCalculatorContext.popStackValue();
}