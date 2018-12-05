#include "EquiLeader.h"

/*
A non-empty array A consisting of N integers is given.

The leader of this array is the value that occurs in more than half of the elements of A.

An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

For example, given array A such that:

	A[0] = 4
	A[1] = 3
	A[2] = 4
	A[3] = 4
	A[4] = 4
	A[5] = 2
we can find two equi leaders:

0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
The goal is to count the number of equi leaders.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

For example, given:

	A[0] = 4
	A[1] = 3
	A[2] = 4
	A[3] = 4
	A[4] = 4
	A[5] = 2
the function should return 2, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int ELsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int len = A.size();
	int equi_leaders = 0;

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
	int total = 0;
	for (int i : A) {
		if (i == leader) total++;
	}
	if (total <= (len / 2)) return 0;

	int ldrCount = 0;
	for (int i = 0; i < len; i++) {
		if (A[i] == leader) ldrCount++;
		int leadersInRightPart = (total - ldrCount);
		if (ldrCount > (i + 1) / 2 && leadersInRightPart > (len - i - 1) / 2) {
			equi_leaders++;
		}
	}

	return equi_leaders;
}
