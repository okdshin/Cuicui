#ifdef ARGUMENT_UNIT_TEST
#include "Argument.h"
#include <iostream>

using namespace cuicui;

int main(int argc, char* argv[])
{
	Argument argument("abc42");
	std::cout << argument.ToInt() << std::endl;

    return 0;
}

#endif
