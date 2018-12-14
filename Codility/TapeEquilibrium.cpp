#include "TapeEquilibrium.h"

/*
A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7
Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int count(std::vector<int>::iterator b, std::vector<int>::iterator e) {
	int sum = 0;
	for (b; b != e; ++b) {
		sum += *b;
	}
	return sum;
}

int TEsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	//auto head = A.begin();
	//auto tail = A.end();
	auto b = A.begin();
	auto e = A.end();

	int fullSize = count(b, e);
	int ret = 0;
	int diff = abs(fullSize - ret);
	for (b; b != (e - 1); ++b) {
		fullSize -= *b;
		ret += *b;
		if (abs(fullSize - ret) < diff)
			diff = abs(fullSize - ret);
	}

	return diff;
}

int TEsolution2(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	auto b = A.begin();
	auto e = A.end();

	if (A.size() == 2)
		return abs(A[0] - A[1]);

	auto fullLambda = [](auto b, auto e) {
		int sum = 0;
		for (; b != e; ++b) {
			//cout << *b << " - " << *e << endl;
			sum += *b;
		}
		//cout << sum << endl;
		return sum;
	};

	int right = fullLambda(b, e);
	int full = right;
	int left = 0;

	for (; b != (e - 1); ++b) {
		left += *b;
		right -= *b;
		//cout << "left: " << left << " right: " << right << " = " << abs(left - right) << endl;
		if (full < 0) {
			if (abs(left - right) > full) {
				full = abs(left - right);
			}
		}
		else {
			if (abs(left - right) < full)
				full = abs(left - right);
		}
	}

	return full;
}