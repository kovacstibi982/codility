#include "MissingInteger.h"

/*
This is a demo task.

Write a function:

    int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].

Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited. 
*/

int MIsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	auto b = A.begin();
	auto e = A.end();
	std::sort(b, e);
	std::set<int> sA(b, e);
	int i = 1;
	for (std::set<int>::iterator it = sA.begin(); it != sA.end(); ++it) {
		if (*it < 1) {
		}
		else if (*it == i) {
			i++;
		}
	}
	return i;
}