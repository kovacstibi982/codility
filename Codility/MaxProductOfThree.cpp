#include "MaxProductOfThree.h"

/*
A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A, returns the value of the maximal product of any triplet.

For example, given array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

/*
Compilation successful.

Example test:    [-3, 1, 2, -2, 5, 6]
OK

Your test case:  [4, 7, 3, 2, 1, -3, -5]
Returned value: 105

Your test case:  [4, 7, 2, 3, 1, -6]
Returned value: 84

Your test case:  [4, 7, -5, 3, 1, -6]
Returned value: 210
*/

int MPOTsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	if (A.size() < 3)
		return 0;

	auto b = A.begin();
	auto e = A.end();

	std::sort(b, e);

	return *(e - 1) * *(e - 2) * *(e - 3);
}

int MPOTsolution2(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	if (A.size() < 3)
		return 0;

	auto b = A.begin();
	auto e = A.end();

	std::sort(b, e);

	if (*(e - 1) < 0) {
		return *(e - 1) * *(e - 2) * *(e - 3);
	}

	if (*b < 0 && *(b + 1) < 0) {
		if (*b * *(b + 1) > *(e - 1) * *(e - 2))
			return *b * *(b + 1) * *(e - 1);
	}

	return *(e - 1) * *(e - 2) * *(e - 3);

}

int MPOTsolution3(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	if (A.size() < 3)
		return 0;

	auto b = A.begin();
	auto e = A.end();

	std::sort(b, e);
	//cout << "b+1: " << *(b + 1) << endl;

	if (*(b + 1) < 0) {
		//cout << "1" << endl;
		if (*b * *(b + 1) * *(e - 1) > *(e - 1) * *(e - 2) * *(e - 3))
			return *b * *(b + 1) * *(e - 1);
		else
			return *(e - 1) * *(e - 2) * *(e - 3);
	}

	return *(e - 1) * *(e - 2) * *(e - 3);
}