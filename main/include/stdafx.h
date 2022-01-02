#if !defined __STDAFX_H
#define __STDAFX_H

#include "Preprocessor.h"

#include <memory>
#include <cassert>  // assert

#include <iostream> // std::cout
#include <fstream>  // std::ifstream
#include <string>	// std::string

// Array
#include <stack>    // std::stack
#include <queue>    // std::queue
#include <list>     // std::list
#include <map>      // std::map

#if defined DEBUG
#	define LOG_ENABLED 1
#else
#	define LOG_ENABLED 0
#endif

using namespace std;

#endif // !defined(__STDAFX_H)
