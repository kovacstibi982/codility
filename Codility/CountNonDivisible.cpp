#include "CountNonDivisible.h"

/*
You are given an array A consisting of N integers.

For each number A[i] such that 0 ≤ i < N, we want to count the number of elements of the array that are not the divisors of A[i]. We say that these elements are non-divisors.

For example, consider integer N = 5 and array A such that:

	A[0] = 3
	A[1] = 1
	A[2] = 2
	A[3] = 3
	A[4] = 6
For the following elements:

A[0] = 3, the non-divisors are: 2, 6,
A[1] = 1, the non-divisors are: 3, 2, 3, 6,
A[2] = 2, the non-divisors are: 3, 3, 6,
A[3] = 3, the non-divisors are: 2, 6,
A[4] = 6, there aren't any non-divisors.
Write a function:

vector<int> solution(vector<int> &A);

that, given an array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.

Result array should be returned as a vector of integers.

For example, given:

	A[0] = 3
	A[1] = 1
	A[2] = 2
	A[3] = 3
	A[4] = 6
the function should return [2, 4, 3, 2, 0], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..50,000];
each element of array A is an integer within the range [1..2 * N].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

std::vector<int> CNDsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	std::vector<int> helper(100000, 0);
	std::vector<int> helper2(100000, 0);
	std::vector<int> notDiv;

	for (auto it = A.begin(); it != A.end(); ++it) {
		auto itNext = A.begin();
		int count = 0;
		if (helper[*it] != 0)
			continue;
		for (itNext; itNext != A.end(); ++itNext) {
			if (*it % *itNext != 0) {
				++count;
			}
		}
		//cout << count << endl;
		helper[*it] = count;
		count = 0;
	}

	for (auto it = A.begin(); it != A.end(); ++it)
		notDiv.push_back(helper[*it]);

	return notDiv;
}
