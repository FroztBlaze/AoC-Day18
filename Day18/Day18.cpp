#include <iostream>
#include <cassert>
#include "../headers/utils.h"

bool split_csv_test() {
	std::string testring("1,2,,3,,\n       \t   ");
	std::vector<std::string> desired_output{ "1","2","","3","" };

	std::vector<std::string> output = Utils::split_line_csv(testring);

	if (desired_output == output) {
		std::cout << "split_csv_test: PASSED.\n";
		return true;
	}
	else {
		std::cout << "split_csv_test: FAILED.\n";
		return false;
	}
}

int main()
{
	assert(split_csv_test());

	std::cout << "\nAll tests ran successfully.\n";
}
