#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>

namespace Utils {

	// Splits a string in csv format.
	//
	// Returns a std::vector containing the splitted strings (without the commas).
	std::vector<std::string> split_line_csv(std::string line);

	// Reads an input file with name given by 'filename'. The variable 'filename'
	// should include the file extension.
	std::vector<std::array<int, 3>> read_input(const std::string& filename);

}

#endif
