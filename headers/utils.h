#ifndef UTILS_H
#define UTILS_H

#include<iostream>
#include <fstream>
#include <string>
#include <vector>

namespace Utils {

	// Splits a string in csv format.
	//
	// Returns a std::vector containing the splitted strings (without the commas).
	std::vector<std::string> split_line_csv(std::string line);

}

#endif
