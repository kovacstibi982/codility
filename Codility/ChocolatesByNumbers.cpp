#include "ChocolatesByNumbers.h"

/*
Two positive integers N and M are given. Integer N represents the number of chocolates arranged in a circle, numbered from 0 to N − 1.

You start to eat the chocolates. After eating a chocolate you leave only a wrapper.

You begin with eating chocolate number 0. Then you omit the next M − 1 chocolates or wrappers on the circle, and eat the following one.

More precisely, if you ate chocolate number X, then you will next eat the chocolate with number (X + M) modulo N (remainder of division).

You stop eating when you encounter an empty wrapper.

For example, given integers N = 10 and M = 4. You will eat the following chocolates: 0, 4, 8, 2, 6.

The goal is to count the number of chocolates that you will eat, following the above rules.

Write a function:

int solution(int N, int M);

that, given two positive integers N and M, returns the number of chocolates that you will eat.

For example, given integers N = 10 and M = 4. the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..1,000,000,000].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

/*
Compilation successful.

Example test:    (10, 4)
OK

Your test case:  [12, 21]
Returned value: 4
*/


int CBNsolution(int N, int M) {
	// write your code in C++14 (g++ 6.2.0)
	std::vector<int> bin(N, 1);
	int index = 0;
	int count = 0;
	while (bin[index] == 1) {
		bin[index] = 0;
		++count;
		if (index + M > N - 1)
			index = (index + N) % M;
		else
			index += M;
		//cout << bin[index] << endl;
	}

	return count;
}

int CBNsolution2(int N, int M) {
	std::vector<int> bin(N, 1);
	int index = 0;
	int count = 0;


	while (bin[index] == 1) {
		bin[index] = 0;
		++count;

		if (N > M) {
			//cout << "index: " << index << endl;
			if (index + M > N - 1) {
				index = (index + N) % M;
				//cout << index << endl;
			}
			else
				index += M;
		}
		else {
			index = (M + index) % N;
		}

		//cout << bin[index] << endl;
	}

	return count;
}

