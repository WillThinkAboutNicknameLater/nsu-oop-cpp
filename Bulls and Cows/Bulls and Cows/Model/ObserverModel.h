#pragma once

class ObserverModel {
public:
	ObserverModel() = default;
	virtual ~ObserverModel() = default;
	virtual void update() = 0;
};

