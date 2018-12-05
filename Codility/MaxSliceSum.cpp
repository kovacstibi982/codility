#include "MaxSliceSum.h"

/*
A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q].

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the maximum sum of any slice of A.

For example, given array A such that:

A[0] = 3  A[1] = 2  A[2] = -6
A[3] = 4  A[4] = 0
the function should return 5 because:

(3, 4) is a slice of A that has sum 4,
(2, 2) is a slice of A that has sum −6,
(0, 1) is a slice of A that has sum 5,
no other slice of A has sum greater than (0, 1).
Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000];
each element of array A is an integer within the range [−1,000,000..1,000,000];
the result will be an integer within the range [−2,147,483,648..2,147,483,647].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int MSSsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	int allSum = 0;
	int s1 = 0, s2 = 0;
	int sum = 0;

	for (unsigned i = 0; i < A.size(); ++i) {
		//cout << "1: " << sum << " A[i]: " << A[i] << endl;
		if (sum + A[i] > allSum) {
			//cout << "bigger" << endl;
			//s2 = i;
			sum += A[i];
			allSum = sum;
		}
		else if (sum + A[i] == allSum) {
			if (i == A.size() - 1) {
				if (A[i] + A[i - 1] > allSum)
					return A[i] + A[i - 1];
			}
			sum += A[i];
		}
		else {
			sum += A[i];
		}
		//cout << "2: " << sum << endl; 
	}

	//cout << "s1: " << s1 << " s2: " << s2 << endl;
	//cout << "Allsum: " << allSum << endl;

	return allSum;
}
