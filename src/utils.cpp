#include "../headers/utils.h"

namespace Utils {

	std::vector<std::string> split_line_csv(std::string line) {
		// Splits a string in csv format.
		//
		// Returns a std::vector containing the splitted strings (without the commas).

		size_t start_idx = 0;
		size_t length = 0;
		std::vector<std::string> result;

		// Right-trim code found in https://stackoverflow.com/q/216823
		line.erase(line.find_last_not_of(" \n\r\t") + 1);

		// Loop through each character in the string
		for (size_t end_idx = 0; end_idx < line.size(); end_idx++) {

			// If a comma is reached or the end of the string is reached, save a substring
			if ((line[end_idx] == ',') || (end_idx == line.size() - 1)) {

				// Calculate the length of the substring
				length = end_idx - start_idx;

				if (length == 0) {
					// Store an empty string if the start index and the end index coincide
					result.push_back("");
				}
				else {
					result.push_back(line.substr(start_idx, length));
				}
				
				// The new start index is after the comma (the end index updates itself)
				start_idx = end_idx + 1;
			}
		}

		return result;
	}

}
