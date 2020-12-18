#pragma once

#include "TContext.h"

class TApp {
public:
	TApp() = default;

	TApp(const std::string& filePath);

	void setFilePath(const std::string& filePath);
	
	void run();

private:
	const std::string QUIT_COMMAND{ "QUIT" };
	TContext _context;
	std::string _filePath{ 0 };

	void readData(std::istream& stream);
};

