#include "MinPerimeterRectangle.h"

/*
An integer N is given, representing the area of some rectangle.

The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).

The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.

For example, given integer N = 30, rectangles of area 30 are:

(1, 30), with a perimeter of 62,
(2, 15), with a perimeter of 34,
(3, 10), with a perimeter of 26,
(5, 6), with a perimeter of 22.
Write a function:

int solution(int N);

that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.

For example, given an integer N = 30, the function should return 22, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000,000].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int MPRsolution(int N) {
	// write your code in C++14 (g++ 6.2.0)

	std::vector<int> divisor;

	for (int i = 1; i <= N; ++i) {
		if (N%i == 0)
			divisor.push_back(i);
	}
	int min = 2 * N + 3;
	int size = divisor.size() / 2;

	for (int i = 0; i < size; ++i) {
		if ((divisor[i] + divisor.back()) * 2 < min)
			min = (divisor[i] + divisor.back()) * 2;
		divisor.pop_back();
	}


	return min;
}

int MPRsolution2(int N) {
	// write your code in C++14 (g++ 6.2.0)
	std::vector<int> divisor;

	if (N < 0)
		return 0;

	for (int i = 1; i <= N; ++i) {
		if (N%i == 0) {
			divisor.push_back(i);
		}
	}
	int min = 2 * N + 3;
	int size = ceil(divisor.size() / 2.0);
	//cout << size << endl;
	for (int i = 0; i < size; ++i) {
		//cout << divisor.back() << endl;
		//cout << divisor[i] + divisor.back() << endl;
		if ((divisor[i] + divisor.back()) * 2 < min)
			min = (divisor[i] + divisor.back()) * 2;
		divisor.pop_back();
	}


	return min;
}
