#pragma once

#include "TOperation.h"

class TDivision : public TOperation {
private:
    void execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) override;
};

