#pragma once

#include "TOperation.h"

class TMultiplication : public TOperation {
private:
    void execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) override;
};

