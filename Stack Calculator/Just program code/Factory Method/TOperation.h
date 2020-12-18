#pragma once

#include <list>

#include "TContext.h"

class TOperation {
public:
	virtual void execute(const std::list<std::string>& arguments, TContext& context) = 0;

	virtual ~TOperation() = default;

};

