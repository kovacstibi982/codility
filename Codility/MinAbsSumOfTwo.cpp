#include "MinAbsSumOfTwo.h"

/*
Let A be a non-empty array consisting of N integers.

The abs sum of two for a pair of indices (P, Q) is the absolute value |A[P] + A[Q]|, for 0 ≤ P ≤ Q < N.

For example, the following array A:

  A[0] =  1
  A[1] =  4
  A[2] = -3
has pairs of indices (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2).
The abs sum of two for the pair (0, 0) is A[0] + A[0] = |1 + 1| = 2.
The abs sum of two for the pair (0, 1) is A[0] + A[1] = |1 + 4| = 5.
The abs sum of two for the pair (0, 2) is A[0] + A[2] = |1 + (−3)| = 2.
The abs sum of two for the pair (1, 1) is A[1] + A[1] = |4 + 4| = 8.
The abs sum of two for the pair (1, 2) is A[1] + A[2] = |4 + (−3)| = 1.
The abs sum of two for the pair (2, 2) is A[2] + A[2] = |(−3) + (−3)| = 6.
Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the minimal abs sum of two for any pair of indices in this array.

For example, given the following array A:

  A[0] =  1
  A[1] =  4
  A[2] = -3
the function should return 1, as explained above.

Given array A:

  A[0] = -8
  A[1] =  4
  A[2] =  5
  A[3] =-10
  A[4] =  3
the function should return |(−8) + 5| = 3.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

/*
Compilation successful.

Example test:    [1, 4, -3]
OK

Example test:    [-8, 4, 5, -10, 3]
OK

Your test case:  [1000000000]
Returned value: 2000000000

Your test case:  []
Returned value: 0

Your test case:  [-1, 2, 6, 7]
Output:
-1
2
6
7
Returned value: 1000000000

Your test case:  [1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3]
Output:
1
2
3
Returned value: 2

Your test case:  [-4, 5]
Output:
-4
5
Returned value: 1
*/

int MASOTsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	std::sort(A.begin(), A.end());

	//auto it = A.begin();
	//auto rit = A.rbegin();

	int size = A.size();
	int min = size;
	int iterMin = 0;
	int forward = 0;
	int backward = size - 1;
	for (; forward != size; ++forward) {
		//cout << "f: " << forward << endl;
		int localMin = size;
		for (; backward >= iterMin; --backward) {
			if (abs(A[forward] + A[backward]) > localMin)
				break;
			//cout << "b: " << backward << endl;
			//cout << abs(A[forward] + A[backward]) << endl;
			if (abs(A[forward] + A[backward]) < min) {
				min = abs(A[forward] + A[backward]);
				localMin = min;
			}
		}
		forward = iterMin;
		backward = size - 1;
		++iterMin;
	}

	return min;
}

int MASOTsolution2(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	std::sort(A.begin(), A.end());
	std::set<int> setA(A.begin(), A.end());

	//for(int s:setA)
	//    cout << s << endl;

	int size = setA.size();
	//int min = 1000000000;

	if (size == 0)
		return 0;

	if (size == 1)
		return abs(2 * *setA.begin());

	auto itAct = setA.begin();
	auto itNext = setA.begin();

	int setMin = abs(2 * *itAct);
	for (; itAct != setA.end(); ++itAct) {
		for (itNext = itAct; itNext != setA.end(); ++itNext) {
			if (abs(*itAct + *itNext) < setMin)
				setMin = abs(*itAct + *itNext);
		}
	}
	//cout << "setMin: " << setMin << endl;
	
	return setMin;
}
