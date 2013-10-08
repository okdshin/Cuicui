#pragma once
//Dispatcher:20130806
#include <iostream>
#include <map>
#include "CommandName.h"
#include "CommandHandler.h"
#include "ArgumentList.h"

namespace cuicui
{
class InvalidCommandErrorHandler {
public:
	InvalidCommandErrorHandler(std::function<void (const CommandName&)> handler) 
		: handler_(handler){}

	auto operator()(const CommandName& command_name)const -> void {
		handler_(command_name);	
	}

private:
	std::function<void (const CommandName&)> handler_;
};

class Dispatcher{
public:
    Dispatcher() 
		: invalid_command_error_handler_(
				[](const CommandName& command_name) -> void {
			throw InvalidCommandError("invalid command");	
		}){}

    Dispatcher(const InvalidCommandErrorHandler& invalid_command_error_handler) 
		: invalid_command_error_handler_(invalid_command_error_handler){}
    
	auto Register(const CommandName& name, const CommandHandler& handler) -> void {
		command_dict_.insert(std::map<CommandName, CommandHandler>::value_type(
			name, handler));
	}

	auto Call(const CommandName& name, const ArgumentList& argument_list)const -> void {
		const auto found = command_dict_.find(name);
		if(found == command_dict_.end()){
			invalid_command_error_handler_(name);
		}
		else {
			(found->second)(argument_list);
		}
	}

private:
	class InvalidCommandError{
	public:
		InvalidCommandError(const std::string& message) : 
			message_(message) {}
		virtual ~InvalidCommandError() throw() {}
		virtual const char* what() const throw() {
			return message_.c_str();
		}
	private:
		const std::string message_;
	};

	std::map<CommandName, CommandHandler> command_dict_;
	InvalidCommandErrorHandler invalid_command_error_handler_;

};
}

