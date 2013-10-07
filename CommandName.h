#pragma once
//CommandName:20130807
#include <iostream>

namespace cuicui
{
class CommandName{
public:
	CommandName():command_name_str_(){}
	CommandName(const std::string& command_name_str) : 
		command_name_str_(command_name_str) {}

	auto operator==(const CommandName& command)const -> bool {
		return command_name_str_ == command.command_name_str_;	
	}
	
	auto operator<(const CommandName& command)const -> bool {
		return command_name_str_ < command.command_name_str_;	
	}

	friend auto operator<<(std::ostream& os, 
			const CommandName& command_name) -> std::ostream& {
		os << command_name.command_name_str_;
		return os;	
	}

private:
	const std::string command_name_str_;
};
}

