#pragma once
//CommandHandler:20130807
#include <iostream>
#include <functional>
#include "ArgumentList.h"

namespace cuicui
{
class CommandHandler{
public:
    CommandHandler() : handler_func_(){} 
    CommandHandler(std::function<void (const ArgumentList&)> handler_func) 
		: handler_func_(handler_func){}

	auto operator()(const ArgumentList& argument_list)const -> void {
		handler_func_(argument_list);	
	}

private:
	std::function<void (const ArgumentList&)> handler_func_;
};
}

