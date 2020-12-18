#pragma once

#include "TOperation.h"

class TComment : public TOperation {
private:
    void execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) override;
};

