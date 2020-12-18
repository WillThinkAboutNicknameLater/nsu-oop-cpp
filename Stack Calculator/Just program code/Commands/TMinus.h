#pragma once

#include "TOperation.h"

class TMinus : public TOperation {
private:
    void execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) override;
};

