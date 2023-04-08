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
	Coords3D first{ 1,2,3 };
	Coords3D second{ 4,5,6 };
	Coords3D third{ 7,8,9 };
	std::set<Coords3D> desired_output{ first, second, third };

	std::string filename("reader_test.csv");
	std::set<Coords3D> output = Utils::read_input(filename);

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
