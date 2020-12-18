#pragma once

#include "TOperation.h"
#include "IOperationMaker.h"
#include "TOperationFactory.h"

#define REGISTER_OPERATION(T, NAME) static TOperationMaker<T> maker(NAME);

template<typename T>
class TOperationMaker : public IOperationMaker {
public:
	TOperationMaker(const std::string& name) {
		TOperationFactory::getInstance().registerOperationMaker(name, this);
	}

	virtual TOperation* create() const {
		return new T();
	}

};

