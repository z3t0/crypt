/*
 * =====================================================================================
 *
 *       Filename:  prime_finder.cpp 
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
#include <time.h>

using namespace std;

void simple() {

	std::vector<int> prime_numbers;

	int testing = 0;

	int found = 0;

	while(1) {

		int pass = 0;

		for(int i = 2; i < testing; i++) {

			if((testing % i) == 0) {
				pass = 1;
				break;
			}
		}

		if(pass) {
			prime_numbers.push_back(testing);
			found++;
			std::cout << "\r" << "Found:" << found;
		}

		if(found == 1000000)
			return;

		testing++;
	}

}

int main() {
	std::cout << "Initialized Prime Finder" << std::endl;

	time_t start = time(0);


	simple();


	double seconds_since_start = difftime( time(0), start);

	std::cout << "Time Passed: " << seconds_since_start << std::endl;

	return 0;
}

