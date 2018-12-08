#include "MinMaxDivision.h"

/*
You are given integers K, M and a non-empty array A consisting of N integers. Every element of the array is not greater than M.

You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.

The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.

The large sum is the maximal sum of any block.

For example, you are given integers K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
The array can be divided, for example, into the following blocks:

[2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
[2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
[2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
[2, 1], [5, 1], [2, 2, 2] with a large sum of 6.
The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.

Write a function:

int solution(int K, int M, vector<int> &A);

that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.

For example, given K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

/*
Example test:    (3, 5, [2, 1, 5, 1, 2, 2, 2])
OK

Your test case:  [3, 5, [2, 1, 5, 2, 2, 2, 2]]
Returned value: 7

Your test case:  [3, 5, [5, 1, 5, 1, 5, 1, 5]]
Returned value: 11

Your test case:  [3, 5, [5, 5, 5, 5, 5, 5, 5]]
Returned value: 15

Your test case:  [3, 5, [2, 2, 2, 2, 2, 2]]
Returned value: 4
*/

int MMDsolution(int K, int M, std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int size = A.size();

	if (size < K)
		return 0;

	int minMax = 0;

	for (int i : A)
		if (i > minMax)
			minMax = i;

	int range1 = 0, range2 = 0, range3 = 0;
	int maxMax = ceil(float(size) / float(K))*M;
	int localMax = maxMax;
	//cout << "maxMax:" << maxMax << endl;
	bool r1 = true, r2 = true;
	while (minMax <= maxMax) {
		//cout << "minMax: " << minMax << endl;
		for (int i = 0; i < size; ++i) {
			if (range1 + A[i] <= minMax && r1) {
				range1 += A[i];
				//cout << "r1: " << range1 << endl;
			}
			else if (range2 + A[i] <= minMax && r2) {
				r1 = false;
				range2 += A[i];
				//cout << "r2: " << range2 << endl;
			}
			else {
				r1 = false;
				r2 = false;
				range3 += A[i];
				//cout << "r3: " << range3 << endl;
			}
		}

		//cout << "1: " << range1 << "     2: " << range2 << "     3: " << range3 << endl;

		int rangeMax = (range1 >= range2 && range1 >= range3) ? range1 : (range2 > range1 && range2 > range3) ? range2 : range3;
		//cout << "rangeMax: " << rangeMax << endl;

		if (rangeMax < localMax)
			localMax = rangeMax;

		if (minMax >= localMax)
			return localMax;

		range1 = range2 = range3 = 0;
		r1 = r2 = true;
		++minMax;
	}


	return minMax;
}
