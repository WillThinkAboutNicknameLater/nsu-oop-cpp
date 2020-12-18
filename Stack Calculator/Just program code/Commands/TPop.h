#pragma once

#include "TOperation.h"

class TPop : public TOperation {
private:
    void execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) override;
};

