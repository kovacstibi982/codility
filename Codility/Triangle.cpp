#include "Triangle.h"

/*
An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

A[P] + A[Q] > A[R],
A[Q] + A[R] > A[P],
A[R] + A[P] > A[Q].
For example, consider array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
Triplet (0, 2, 4) is triangular.

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

For example, given array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
the function should return 1, as explained above. Given array A such that:

  A[0] = 10    A[1] = 50    A[2] = 5
  A[3] = 1
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int Tsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	if (A.size() < 3)
		return 0;

	auto b = A.begin();
	auto e = A.end();
	std::sort(b, e);
	//for(int i:A)
		//cout << i << endl;

	auto first = b, second = b + 1, third = b + 2;
	for (third; third != A.end(); ++third) {
		//cout << *first <<endl;
		if (*first <= 0 || *second <= 0 || *third <= 0) {
			++first;
			++second;
			continue;
		}
		//cout << *first << " " << *second << " " << *third <<endl;
		if ((*first + *second) > *third)
			return 1;
		++first;
		++second;
	}

	return 0;
}
