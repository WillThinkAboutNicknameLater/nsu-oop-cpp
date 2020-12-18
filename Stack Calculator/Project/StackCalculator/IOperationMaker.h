#pragma once

#include "TOperation.h"

class IOperationMaker {
public: 
	virtual TOperation* create() const = 0;

	virtual ~IOperationMaker() = default;

};

