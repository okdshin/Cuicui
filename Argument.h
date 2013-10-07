#pragma once
//Argument:20130807
#include <iostream>
#include <sstream>

namespace cuicui
{
class Argument {
public:
	explicit Argument(const std::string& argument_str) 
		: argument_str_(argument_str){}
	auto ToString()const -> std::string {
		return argument_str_;	
	}

	auto ToInt()const -> int {
		std::istringstream iss(argument_str_);
		int res;
		iss >> res;
		return res;
	}

private:
	std::string argument_str_;
};

}

