#include "Dominator.h"

/*
An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

For example, consider array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return −1 if array A does not have a dominator.

For example, given array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int DomSolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	int len = A.size();
	int leader = A[0];
	int ctr = 1;

	for (int i = 1; i < len; i++) {
		if (A[i] == leader) ctr++;
		else ctr--;
		if (ctr == 0) {
			ctr = 1;
			leader = A[i];
		}
	}
	int count = 0;
	for (int i : A) {
		if (i == leader)
			++count;
	}

	if (count > (len / 2)) {
		auto it = find(A.begin(), A.end(), leader);
		int index = std::distance(A.begin(), it);
		return index;
	}

	return -1;
}
