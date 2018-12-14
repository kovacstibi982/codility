#include "MaxCounters.h"

/*
You are given N counters, initially set to 0, and you have two possible operations on them:

increase(X) − counter X is increased by 1,
max counter − all counters are set to the maximum value of any counter.
A non-empty array A of M integers is given. This array represents consecutive operations:

if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.
For example, given integer N = 5 and array A such that:

	A[0] = 3
	A[1] = 4
	A[2] = 4
	A[3] = 6
	A[4] = 1
	A[5] = 4
	A[6] = 4
the values of the counters after each consecutive operation will be:

	(0, 0, 1, 0, 0)
	(0, 0, 1, 1, 0)
	(0, 0, 1, 2, 0)
	(2, 2, 2, 2, 2)
	(3, 2, 2, 2, 2)
	(3, 2, 2, 3, 2)
	(3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.

Write a function:

vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers representing the values of the counters.

Result array should be returned as a vector of integers.

For example, given:

	A[0] = 3
	A[1] = 4
	A[2] = 4
	A[3] = 6
	A[4] = 1
	A[5] = 4
	A[6] = 4
the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

std::vector<int> MCsolution(int N, std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	int max = 0;
	std::vector<int> rA(N);

	for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
		if ((*it >= 1) && (*it <= N)) {
			++rA[(*it) - 1];
			if (rA[(*it) - 1] > max)
				max = rA[(*it) - 1];
		}
		else if (*it == (N + 1)) {
			for (auto it2 = rA.begin(); it2 != rA.end(); ++it2)
				*it2 = max;
		}
	}

	return rA;
}

//std::vector<int> MCsolution2(int N, std::vector<int> &A) {
//	// write your code in C++14 (g++ 6.2.0)
//	int max = 0;
//	int arr[N] = { 0 };
//
//	for (auto it = A.begin(); it != A.end(); ++it) {
//		if (*it >= 1 && *it <= N) {
//			++arr[(*it) - 1];
//			if (arr[(*it) - 1] > max) {
//				max = arr[(*it) - 1];
//			}
//		}
//		else if (*it == (N + 1)) {
//			std::fill_n(arr, N, max);
//		}
//	}
//
//	return std::vector<int>(arr, arr + sizeof(arr) / sizeof(*arr));
//}

std::vector<int> MCsolution3(int N, std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	int max = 0;
	bool cp = 1;
	std::vector<int> rA(N);
	std::vector<int> reduce;
	for (int i : A) {
		if (i <= N && i >= 1) {
			reduce.push_back(i);
			cp = 1;
		}
		else if (A[i] == (N + 1)) {
			if (cp) {
				reduce.push_back(i);
			}
			cp = 0;
		}
	}

	for (int i : A) {
		if ((i >= 1) && (i <= N)) {
			++rA[i - 1];
			//cout << rA[0] << rA[1] << rA[2] << rA[3] << rA[4]  << endl;
			if (rA[i - 1] > max)
				max = rA[i - 1];
		}
		else if (i == (N + 1)) {
			for (int j = 0; j < rA.size(); ++j) {
				rA[j] = max;
			}
		}
	}

	return rA;
}


std::vector<int> MCsolution4(int N, std::vector<int> &A) {
	int max = 0;

	std::vector<int> rA(N, 0);
	
	for (int i : A) {
		if (i <= N) {
			++rA[i - 1];
			if (rA[i - 1] > max)
				max = rA[i - 1];
		}
		else if (i == N + 1) {
			std::vector<int> r2(N, max);
			rA = r2;
		}
	}

	return rA;

}

