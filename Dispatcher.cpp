#ifdef DISPATCHER_UNIT_TEST
#include "Dispatcher.h"
#include <iostream>

using namespace cuicui;

int main(int argc, char* argv[])
{
	Dispatcher dispatcher;
	dispatcher.Register(CommandName("test"), 
		CommandHandler([](const ArgumentList&)->void{
			std::cout << "test hello" << std::endl;
		})
	);
	dispatcher.Register(CommandName("sample"), 
		CommandHandler([](const ArgumentList&)->void{
			std::cout << "sample hello" << std::endl;
		})
	);
	dispatcher.Call(CommandName("test"), ArgumentList());
	dispatcher.Call(CommandName("sample"), ArgumentList());
	dispatcher.Call(CommandName("sampletest"), ArgumentList());

    return 0;
}

#endif
