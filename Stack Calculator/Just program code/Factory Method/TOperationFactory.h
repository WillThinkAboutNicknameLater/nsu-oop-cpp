#pragma once

#include <iostream>

#include "TOperation.h"
#include "IOperationMaker.h"

class TOperationFactory {
public:
	TOperationFactory(const TOperationFactory&) = delete;

	static TOperationFactory& getInstance();

	void registerOperationMaker(const std::string& name, IOperationMaker* maker);

	TOperation* createOperation(const std::string& name) const;

private:
	TOperationFactory() = default;

	std::map<std::string, IOperationMaker*> _makers;
};

