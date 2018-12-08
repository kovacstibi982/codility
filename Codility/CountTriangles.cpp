﻿#include "CountTriangles.h"

/*
An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if it is possible to build a triangle with sides of lengths A[P], A[Q] and A[R]. In other words, triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

A[P] + A[Q] > A[R],
A[Q] + A[R] > A[P],
A[R] + A[P] > A[Q].
For example, consider array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 12
There are four triangular triplets that can be constructed from elements of this array, namely (0, 2, 4), (0, 2, 5), (0, 4, 5), and (2, 4, 5).

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the number of triangular triplets in this array.

For example, given array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 12
the function should return 4, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..1,000];
each element of array A is an integer within the range [1..1,000,000,000].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

/*

*/

int CTsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	if (A.size() < 3)
		return 0;

	int count = 0;
	std::sort(A.begin(), A.end());
	auto it = A.begin();
	auto itNext = it + 1;
	auto itNextNext = itNext + 1;

	for (it; it != A.end() - 2; ++it) {
		for (itNext = it + 1; itNext != A.end() - 1; ++itNext) {
			for (itNextNext = itNext + 1; itNextNext != A.end(); ++itNextNext) {
				if (*it + *itNext > *itNextNext)
					++count;
				//cout << *it << " " << *itNext << " " << *itNextNext << endl;
			}

		}
	}
	//cout << count << endl;
	return count;
}
