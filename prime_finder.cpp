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
#include <fstream>
#include <vector>
#include <time.h>
#include <math.h>

using namespace std;

std::vector<int> prime_numbers;

// Checks each number < testing to check for primality
void raw(unsigned long long low, unsigned long long high){
	std::cout << "Testing from " << low << " to " << high << std::endl;

	// Loop checks all numbers between low and high for primality
	for (unsigned long long i = low; i < high; i++) {

		int pass = 1; // 1 is prime

		if (i < 2)
			continue;

		/* std::cout << "testing " << i << std::endl; */

		for (unsigned long long j = 2; j < i; j++) {

		/* std::cout << "j = " << j << std::endl; */

			if((i % j) != 0)
			{
				// still prime
			}

			else {
				// False
				pass = 0;
				break;
			}
		}


		if(pass) {
			// Add to list
			std::cout << i << std::endl;
			prime_numbers.push_back(i);
		}
	}

	std::cout << "Finished testing..." << std::endl;
}

void count (unsigned long long low, unsigned long long high) {
	std::cout << "Testing from " << low << " to " << high << std::endl;

	unsigned long long total = 0;

	// Loop checks all numbers between low and high for primality
	for (unsigned long long i = low; i < high; i++) {

		int pass = 1; // 1 is prime

		if (i < 2)
			continue;
		/* std::cout << "testing " << i << std::endl; */

		for (unsigned long long j = 2; j < i; j++) {

		/* std::cout << "j = " << j << std::endl; */

			if((i % j) != 0)
			{
				// still prime
			}

			else {
				// False
				pass = 0;
				break;
			}
		}
		if(pass) {
			// Add to list
			total++;
			prime_numbers.push_back(i);
		}
	}

	std::cout << "Finished testing. With " << total << " prime numbers between " << low << " and " << high << std::endl;
}

void timer(unsigned long long low, unsigned long long high) {

	std::cout << "Testing from " << low << " to " << high << std::endl;

	unsigned long long total = 0;

	// Loop checks all numbers between low and high for primality
	for (unsigned long long i = low; i < high; i++) {

		time_t timing = time(0);
		int pass = 1; // 1 is prime

		if (i < 2)
			continue;

		/* std::cout << "i = "  << i << std::endl; */

		for (unsigned long long j = 2; j < low; j++) {

		/* std::cout << "j = "  << j << std::endl; */

			if((i % j) != 0)
			{
				// still prime
			}

			else {
				// False
				pass = 0;
				break;
			}
		}


		if(pass) {
			// Add to list
			double time_taken = difftime( time(0), timing);
			std::cout << total << " | " << i <<  " | " << time_taken << "s" << std::endl;
			total++;
			prime_numbers.push_back(i);
		}
	}

	std::cout << "Finished testing" << std::endl;
}

// Print out list
void print() {

	cout << "Prime Numbers found: " << std::endl;

	for (std::vector<int>::iterator it = prime_numbers.begin() ; it != prime_numbers.end(); ++it) {
    	std::cout << *it << std::endl;
	}
  	std::cout << '\n';

}

// Write to Filename
void writeToFile() {

	string fileName = "";
	cout << "Enter a file name to save the result: ";
	cin >> fileName;

	ofstream file;
	file.open(fileName);

	cout << "writing to file" << std::endl;

	copy(prime_numbers.begin(), prime_numbers.end(), ostream_iterator<int>(file, ","));

  	file << std::endl;
	file.close();

	cout << "Written to file : " << fileName << std::endl;

}

int main() {
	std::cout << "Initialized Prime Finder" << std::endl;

	unsigned long long lower;
	unsigned long long higher;

	cout << "Please enter the LOWER limit: ";
	cin >> lower;

	cout << "Please enter the HIGHER limit: ";
	cin >> higher;

	cout << "Prime Finders: " << std::endl <<
	"Options:"  << std::endl <<
	"1) Raw check" << std::endl <<
	"2) Count check" << std::endl <<
	"3) Time check" << std::endl;

	int option = 0;

	while (option != 1 && option !=2 && option !=3) {
		cout << "Which prime finder would you like to use: ";
		cin >> option;
	}

	time_t start = time(0);

	switch(option) {
		case 1:
			raw(lower, higher);
			break;
		case 2:
			count(lower, higher);
			break;
		case 3:
			timer(lower, higher);
				break;
		default:
			std::cout << "No option selected, error!" << std::endl;
			return -1;
			break;
	}
	double seconds_since_start = difftime( time(0), start);

	std::cout << "Time Passed: " << seconds_since_start << std::endl;

	/* writeToFile(); */

	return 0;
}

