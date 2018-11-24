#include "PermMissingElem.h"

/*
An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(vector<int> &A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int PMEsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	auto b = A.begin();
	auto e = A.end();
	std::sort(b, e);

	int ret = 1;

	for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
	{
		//cout << *it << " " << ret << endl;
		if (*it != ret)
			return ret;
		ret++;
	}

	return ret;
}