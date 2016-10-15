/*
 * =====================================================================================
 *
 *       Filename:  prime_finder.cpp
 *
 *    Description:  Different algorithsm for finding prime numbers
 *
 *        Version:  1.0
 *        Created:  10/12/2016 14:37:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rafi Khan
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

void simple() {

	std::vector<int> prime_numbers;

	int testing = 0;

	while(1) {

		int pass = 0;

		for(int i = 0; i < testing; i++) {

			if((testing % i) == 0) {
				pass = 1;
				break;
			}
		}

		if(pass) {
			prime_numbers.push_back(testing);
			std::cout << testing << std::endl;
		}

		testing++;
	}

}

int main() {
	std::cout << "Initialized Prime Finder" << std::endl;

	int testing = 0;

	while(1) {
		int passed = 1;

		for (int i = 2; i < testing; i++) {
			if(testing % i == 0) {
				passed = 0;
				break;
			}
		}

		if(passed) {
			std::cout << "Prime: " << testing << std::endl;
		}

			testing++;

	}

	/* simple(); */

	return 0;
}

