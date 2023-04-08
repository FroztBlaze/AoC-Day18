#include "../headers/tests.h"

bool split_csv_test() {
	std::string testring("1,2,,3,,\n       \t   ");
	std::vector<std::string> desired_output{ "1","2","","3","","" };

	std::vector<std::string> output = Utils::split_line_csv(testring);

	if (desired_output == output) {
		std::cout << "split_csv_test: PASSED\n";
		return true;
	}
	else {
		std::cout << "split_csv_test: FAILED\n";
		return false;
	}
}

bool read_input_test() {
	std::array<int, 3> first{ 1,2,3 };
	std::array<int, 3> second{ 4,5,6 };
	std::array<int, 3> third{ 7,8,9 };
	std::vector<std::array<int, 3>> desired_output{ first, second, third };

	std::string filename("reader_test.csv");
	std::vector<std::array<int, 3>> output = Utils::read_input(filename);

	if (desired_output == output) {
		std::cout << "read_input_test: PASSED.\n";
		return true;
	}
	else {
		std::cout << "read_input_test: FAILED.\n";
		return false;
	}
}

void run_tests() {
	assert(split_csv_test());
	assert(read_input_test());

	std::cout << "\nAll tests ran successfully.\n";
}
