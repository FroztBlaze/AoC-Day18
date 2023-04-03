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
			bool comma_encountered = (line[end_idx] == ',');
			bool end_encountered = (end_idx == line.size() - 1);

			// If a comma is reached or the end of the line is reached, save a substring
			if (comma_encountered || end_encountered) {

				// Calculate the length of the substring
				length = end_idx - start_idx;
				
				if (comma_encountered && end_encountered) {
					// If the end of the line is a comma, return an additional empty string
					result.push_back(line.substr(start_idx, length));
					result.push_back("");
				}
				else if ((length == 0) && end_encountered) {
					// If the end of the line is not a comma and the length is zero, return
					// the last character as the final string
					result.push_back(line.substr(start_idx, 1));
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

	std::vector<std::array<int,3>> read_input(const std::string& filename) {
		// Reads an input file with name given by 'filename'. The variable 'filename'
		// should include the file extension.

		// Initialize the result
		std::vector<std::array<int, 3>> result;

		// Open the file containing the designs
		std::string filepath = "../inputs/" + filename;
		std::ifstream ifile(filepath);

		// Check whether the file is open
		if (ifile.is_open()) {

			// Initialise a string to store the lines in
			std::string temp_line;

			// Read all lines
			while (std::getline(ifile, temp_line)) {

				std::array<int, 3> temp_coords;
				
				// Split the current line
				std::vector<std::string> split_line = split_line_csv(temp_line);

				// Convert the string coordinates to ints
				for (int i = 0; i < 3; i++) {
					temp_coords[i] = std::stoi(split_line[i]);
				}

				// Save these coordinates
				result.push_back(temp_coords);
			}

			// Close the design file and clear the relevant vectors
			ifile.close();
		}
		else {
			std::cout << "\nUNABLE TO OPEN INPUT FILE\n";
		}

		return result;
	}

}
