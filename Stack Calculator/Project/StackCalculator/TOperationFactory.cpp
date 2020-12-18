#include "TOperationFactory.h"
#include "TErrorHandler.h"

TOperationFactory& TOperationFactory::getInstance() {
	static TOperationFactory factory;
	return factory;
}

void TOperationFactory::registerOperationMaker(const std::string& name, IOperationMaker* maker) {
	if (_makers.find(name) != _makers.end()) {
		throw TOperationNameIsTaken();
	} 
	_makers[name] = maker;
}

TOperation* TOperationFactory::createOperation(const std::string& name) const {
	auto candidate{ _makers.find(name) };

	if (candidate == _makers.end()) {
		throw TOperationDoesNotExist();
	}

	IOperationMaker* maker{ candidate->second };
	return maker->create();
}
