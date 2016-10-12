/*
 * =====================================================================================
 *
 *       Filename:  prime_finder.c
 *
 *    Description:  Finds prime numbers
 *
 *        Version:  1.0
 *        Created:  10/10/2016 20:31:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rafi Khan
 *
 * =====================================================================================
 */
#include <stdio.h>

int main() {

	long long prime_numbers[1000000]
	long long test = 0;

	while(1) {
		int passed = 1;

		for (long long i = 2; i < test; i++) {
			if (test % i == 0) {
				passed = 0;
				break;
			}
		}

		if(passed) {

			printf("Prime Number: %lli\n", test);
		}

		test++;

	}

	return 0;
}
