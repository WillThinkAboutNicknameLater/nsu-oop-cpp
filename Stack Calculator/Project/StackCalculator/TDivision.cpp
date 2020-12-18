#include "TDivision.h"
#include "TOperationMaker.h"
#include "TErrorHandler.h"

REGISTER_OPERATION(TDivision, "/");

void TDivision::execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) {
    if (executionCalculatorContext.getStackSize() < 2) {
        throw TWrongStackSize();
	}

    double numerator{ executionCalculatorContext.popStackValue() };
    double denominator{ executionCalculatorContext.popStackValue() };

    if (denominator == 0) {
        executionCalculatorContext.pushStackValue(denominator);
        executionCalculatorContext.pushStackValue(numerator);
        throw TDivisionByZero();
    }

	executionCalculatorContext.pushStackValue(numerator / denominator);
}
