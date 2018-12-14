#include "CountDistinctSlices.h"

/*
An integer M and a non-empty array A consisting of N non-negative integers are given. All integers in array A are less than or equal to M.

A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The slice consists of the elements A[P], A[P + 1], ..., A[Q]. A distinct slice is a slice consisting of only unique numbers. That is, no individual number occurs more than once in the slice.

For example, consider integer M = 6 and array A such that:

	A[0] = 3
	A[1] = 4
	A[2] = 5
	A[3] = 5
	A[4] = 2
There are exactly nine distinct slices: (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4).

The goal is to calculate the number of distinct slices.

Write a function:

int solution(int M, vector<int> &A);

that, given an integer M and a non-empty array A consisting of N integers, returns the number of distinct slices.

If the number of distinct slices is greater than 1,000,000,000, the function should return 1,000,000,000.

For example, given integer M = 6 and array A such that:

	A[0] = 3
	A[1] = 4
	A[2] = 5
	A[3] = 5
	A[4] = 2
the function should return 9, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..M].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

/*
Compilation successful.

Example test:    (6, [3, 4, 5, 5, 2])
OK

Your test case:  [6, [3, 4, 2, 5, 5]]
Returned value: 11

Your test case:  [6, [3, 4, 5, 5, 2, 1, 3]]
Returned value: 16

Your test case:  [6, [6, 5, 6, 5, 6, 5, 6]]
Returned value: 6

Your test case:  [6, [1, 2, 3, 1, 2, 3]]
Returned value: 10
*/

int CDSsolution(int M, std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	int sum = 0;

	std::vector<int> slices;
	slices.push_back(1);

	for (int i = 1; i <= M; ++i) {
		slices.push_back(i + 1 + slices[i - 1]);
	}

	//for(int s:slices)
	//    cout << s << endl;

	//int count = 0;
	std::set<int> setSlice;
	unsigned before = 0;
	for (unsigned i = 0; i < A.size(); ++i) {
		before = setSlice.size();
		//cout << "before: " << before << endl;
		setSlice.insert(A[i]);
		//cout << "after: " << setSlice.size() << endl;
		if (before == setSlice.size()) {
			sum += slices[before - 1];
			//cout << "add: " << slices[before-1] << endl;
			setSlice.clear();
			setSlice.insert(A[i]);
			before = 0;
		}
	}
	//cout << "end before: " << before << endl;
	sum += slices[before];
	//cout << sum << endl;

	return sum;
}
