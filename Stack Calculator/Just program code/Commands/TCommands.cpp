#include <iomanip>

#include "TCommands.h"
#include "TOperationMaker.h"

REGISTER_OPERATION(TCommands, "COMMANDS");

void TCommands::execute(const std::list<std::string>& executionArguments, TContext& executionCalculatorContext) {
	const size_t INDENT{ 10 };
	std::cout << std::left << std::setw(INDENT) << "#" << "line with a comment" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "POP" << "pop a number from the stack" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "PUSH" << "push a number on the stack" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "+" << "addition operation" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "-" << "subtraction operation" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "*" << "multiplication operation" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "/" << "division operation" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "SQRT" << "root extraction operation" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "PRINT" << "print the top of the stack" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "DEFINE" << "set variable" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "COMMANDS" << "print command list" << std::endl;
	std::cout << std::left << std::setw(INDENT) << "QUIT" << "quit the application" << std::endl;
}
