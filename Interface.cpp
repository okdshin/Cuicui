#ifdef INTERFACE_UNIT_TEST
#include "Interface.h"
#include <iostream>

using namespace cuicui;

int main(int argc, char* argv[])
{
	Interface interface(
		LineParser([](const std::string& line) -> CommandNameWithArgumentList {
			std::cout << "you commanded \"" << line << 
				"\" but i command \"test_command\"" << std::endl;
			ArgumentList argument_list;
			argument_list.Pushback(Argument("test_argument"));
			return CommandNameWithArgumentList(
				CommandName("test_command"), argument_list);
		}),
		InvalidCommandErrorHandler([](const CommandName& command_name) -> void {
			std::cout << "invalid command name \"" << command_name << "\"" << std::endl;	
		}));
	interface.Register(CommandName("test_command"), 
		CommandHandler([](const ArgumentList& arg_list){
			std::cout << "hello world" << std::endl;	
		})
	);

	Interface::StartMainLoop(interface);

    return 0;
}

#endif
