#pragma once

#include <vector>

#include "ObserverModel.h"

class ObservableModel {
public:
	void addObserver(ObserverModel* observer);
	void notifyUpdate();

private:
	std::vector<ObserverModel*> _observers;
};

