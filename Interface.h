#pragma once
//Interface:20130806
#include <iostream>
#include "Dispatcher.h"

namespace cuicui
{

class CommandNameWithArgumentList {
public:
	CommandNameWithArgumentList(
		const CommandName& command_name, const ArgumentList& argument_list) 
	: command_name_(command_name), argument_list_(argument_list){}

	auto GetCommandName()const -> CommandName {
		return command_name_;	
	}

	auto GetArgumentList()const -> ArgumentList {
		return argument_list_;	
	}

private:
	const CommandName command_name_;
	const ArgumentList argument_list_;

};

class LineParser {
public:
	LineParser(
			std::function<CommandNameWithArgumentList (const std::string&)> func) 
		: func_(func){}

	auto operator()(const std::string& line)const -> CommandNameWithArgumentList {
		return func_(line);
	}
private:
	std::function<CommandNameWithArgumentList (const std::string&)> func_;
};

class Interface{
public:
    Interface(
		const LineParser& line_parser,
		const InvalidCommandErrorHandler& invalid_command_error_handler) 
		: line_parser_(line_parser), 
		dispatcher_(invalid_command_error_handler){}
    ~Interface(){}

	static auto InputCommandLine(const Interface& interface, int argc, char**argv) -> void {
		std::string line = "";
		for(int i = 1; i < argc; ++i){
			line += std::string(argv[i]) + " ";
		}
		interface.InputLine(line);
	}

	static auto StartMainLoop(const Interface& interface) -> void {
		std::string line;
		while(true){
			std::getline(std::cin, line);
			interface.InputLine(line);
		}
	}

	auto InputLine(const std::string& line)const -> void {
		const auto command_name_with_argument_list = line_parser_(line);
		dispatcher_.Call(
			command_name_with_argument_list.GetCommandName(),
			command_name_with_argument_list.GetArgumentList());	
	}

private:
	LineParser line_parser_;
	Dispatcher dispatcher_;
};
}

