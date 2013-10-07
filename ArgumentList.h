#pragma once
//ArgumentList:20130807
#include <iostream>
#include <vector>
#include <cassert>
#include "Argument.h"

namespace cuicui
{
class ArgumentList{
public:
    ArgumentList(){}
    ~ArgumentList(){}

	auto Pushback(const Argument& argument) -> void {
		argument_vect_.push_back(argument);
	}

	auto At(unsigned int index)const -> Argument {
		assert(index < argument_vect_.size());
		return argument_vect_[index];	
	}

	auto Size()const -> unsigned int {
		return argument_vect_.size();	
	}

private:
	std::vector<Argument> argument_vect_;

};
}

