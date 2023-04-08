#include "../headers/tests.h"

size_t solve_problem() {
	// Initialize the result
	size_t result = 0;

	// Initialize coordinates to be used as incrementors or decrementors
	const Coords3D x = { 1, 0, 0 };
	const Coords3D y = { 0, 1, 0 };
	const Coords3D z = { 0, 0, 1 };
	const Coords3D minus_x = { -1, 0, 0 };
	const Coords3D minus_y = { 0, -1, 0 };
	const Coords3D minus_z = { 0, 0, -1 };
	const std::vector<Coords3D> incrementors = { x, y, z, minus_x, minus_y, minus_z };

	// Read the input coordinates
	const std::string filename("test_puzzle_input.csv");
	const std::set<Coords3D> coordinates = Utils::read_input(filename);

	// Iterate through every element in the set of coordinates
	//
	// Code to iterate through sets adapted from https://stackoverflow.com/a/12863273
	std::set<Coords3D>::iterator it;
	for (it = coordinates.begin(); it != coordinates.end(); ++it) {
		const Coords3D current_coords = *it;
		size_t local_exposed_faces = 6; // Max. xposed faces in 3D space
		Coords3D test_coords = *it;

		// Check whether each neigbouring block is in the set of coordinates
		for (size_t i = 0; i < incrementors.size(); i++) {
			const Coords3D incrementor = incrementors[i];
			test_coords = Utils::add_coords(current_coords, incrementor);

			// Remove one to the number of exposed faces
			if (coordinates.count(test_coords) > 0) {
				local_exposed_faces += -1;
			}
		}

		// Add the remaining number of exposed faces to the result
		result += local_exposed_faces;
	}

	return result;
}

int main(){
	//run_tests();
	solve_problem();
}
