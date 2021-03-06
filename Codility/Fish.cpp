﻿#include "Fish.h"

/*
You are given two non-empty arrays A and B consisting of N integers. Arrays A and B represent N voracious fish in a river, ordered downstream along the flow of the river.

The fish are numbered from 0 to N − 1. If P and Q are two fish and P < Q, then fish P is initially upstream of fish Q. Initially, each fish has a unique position.

Fish number P is represented by A[P] and B[P]. Array A contains the sizes of the fish. All its elements are unique. Array B contains the directions of the fish. It contains only 0s and/or 1s, where:

0 represents a fish flowing upstream,
1 represents a fish flowing downstream.
If two fish move in opposite directions and there are no other (living) fish between them, they will eventually meet each other. Then only one fish can stay alive − the larger fish eats the smaller one. More precisely, we say that two fish P and Q meet each other when P < Q, B[P] = 1 and B[Q] = 0, and there are no living fish between them. After they meet:

If A[P] > A[Q] then P eats Q, and P will still be flowing downstream,
If A[Q] > A[P] then Q eats P, and Q will still be flowing upstream.
We assume that all the fish are flowing at the same speed. That is, fish moving in the same direction never meet. The goal is to calculate the number of fish that will stay alive.

For example, consider arrays A and B such that:

  A[0] = 4    B[0] = 0
  A[1] = 3    B[1] = 1
  A[2] = 2    B[2] = 0
  A[3] = 1    B[3] = 0
  A[4] = 5    B[4] = 0
Initially all the fish are alive and all except fish number 1 are moving upstream. Fish number 1 meets fish number 2 and eats it, then it meets fish number 3 and eats it too. Finally, it meets fish number 4 and is eaten by it. The remaining two fish, number 0 and 4, never meet and therefore stay alive.

Write a function:

int solution(vector<int> &A, vector<int> &B);

that, given two non-empty arrays A and B consisting of N integers, returns the number of fish that will stay alive.

For example, given the arrays shown above, the function should return 2, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [0..1,000,000,000];
each element of array B is an integer that can have one of the following values: 0, 1;
the elements of A are all distinct.
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

/*
([4,3,2,1,5],[0,1,0,0,1])

([13,4,16,9,17,2,8,1,6,18,19,20,14,10,5,3,12,7,15,11],[1,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,1])
*/

int Fsolution(std::vector<int> &A, std::vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)
	int count = 0;
	std::stack<int> s;
	int direction = B[0];
	int size = A.size();
	for (int i = 0; i < size; ++i) {
		std::cout << "i size: " << s.size() << std::endl;
		if (s.empty()) {
			std::cout << "empty" << std::endl;
			s.push(A[i]);
			direction = B[i];
			continue;
		}
		std::cout << "direction: " << direction << " B[i]: " << B[i] << std::endl;
		if (direction == 0 && B[i] == 1) {
			std::cout << "clear, s: " << s.size() << std::endl;
			count += s.size();
			while (!s.empty()) {
				s.pop();
			}
			s.push(A[i]);
			direction = B[i];
			continue;
		}

		if (direction == B[i]) {
			std::cout << "same" << std::endl;
			s.push(A[i]);
		}
		else if (A[i] > s.top()) {
			std::cout << "bigget" << std::endl;
			while (!s.empty() && A[i] > s.top()) {
				s.pop();
			}
			s.push(A[i]);
			direction = B[i];
		}
		else if (A[i] < s.top()) {
			std::cout << "smaller" << std::endl;
		}
	}
	std::cout << "size: " << s.size() << std::endl;
	count += s.size();

	return count;
}

int Fsolution2(std::vector<int> &A, std::vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)
	int count = 0;
	std::stack<int> s;
	int direction = B[0];
	int size = A.size();
	for (int i = 0; i < size; ++i) {
		//cout << "i size: " << s.size() << endl;
		if (s.empty()) {
			//cout << "empty" << endl;
			s.push(A[i]);
			direction = B[i];
			continue;
		}
		//cout << "direction: " << direction << " B[i]: " << B[i] << endl;
		if (direction == 0 && B[i] == 1) {
			//cout << B[i] << " " << A[i] << endl;
			count += s.size();
			//cout << "clear, s: " << s.size() << endl;
			while (!s.empty()) {
				s.pop();
			}
			s.push(A[i]);
			direction = B[i];
			continue;
		}

		if (direction == B[i]) {
			//cout << "same" << endl;
			s.push(A[i]);
		}
		else if (A[i] > s.top()) {
			//cout << "bigget" << endl;
			while (!s.empty()) {
				s.pop();
			}
			s.push(A[i]);
			direction = B[i];
		}
		else if (A[i] < s.top()) {
			//cout << "smaller" << endl;
		}
	}
	count += s.size();
	//cout << "count: " << count << endl;
	//cout << "size: " << s.size() << endl;
	return count;
}

