#include "ObservableModel.h"

void ObservableModel::addObserver(ObserverModel* observer) {
	_observers.push_back(observer);
}

void ObservableModel::notifyUpdate() {
	size_t size{ _observers.size() };
	for (size_t idx{ 0 }; idx < size; ++idx) {
		_observers[idx]->update();
	}
}
