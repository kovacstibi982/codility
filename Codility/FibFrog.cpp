#include "FibFrog.h"

/*
The Fibonacci sequence is defined using the following recursive formula:

	F(0) = 0
	F(1) = 1
	F(M) = F(M - 1) + F(M - 2) if M >= 2
A small frog wants to get to the other side of a river. The frog is initially located at one bank of the river (position −1) and wants to get to the other bank (position N). The frog can jump over any distance F(K), where F(K) is the K-th Fibonacci number. Luckily, there are many leaves on the river, and the frog can jump between the leaves, but only in the direction of the bank at position N.

The leaves on the river are represented in an array A consisting of N integers. Consecutive elements of array A represent consecutive positions from 0 to N − 1 on the river. Array A contains only 0s and/or 1s:

0 represents a position without a leaf;
1 represents a position containing a leaf.
The goal is to count the minimum number of jumps in which the frog can get to the other side of the river (from position −1 to position N). The frog can jump between positions −1 and N (the banks of the river) and every position containing a leaf.

For example, consider array A such that:

	A[0] = 0
	A[1] = 0
	A[2] = 0
	A[3] = 1
	A[4] = 1
	A[5] = 0
	A[6] = 1
	A[7] = 0
	A[8] = 0
	A[9] = 0
	A[10] = 0
The frog can make three jumps of length F(5) = 5, F(3) = 2 and F(5) = 5.

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the minimum number of jumps by which the frog can get to the other side of the river. If the frog cannot reach the other side of the river, the function should return −1.

For example, given:

	A[0] = 0
	A[1] = 0
	A[2] = 0
	A[3] = 1
	A[4] = 1
	A[5] = 0
	A[6] = 1
	A[7] = 0
	A[8] = 0
	A[9] = 0
	A[10] = 0
the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer that can have one of the following values: 0, 1.
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int FFsolution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	int size = A.size();
	std::vector<int> fib;
	fib.push_back(0);
	fib.push_back(1);
	//cout << size << endl;

	int i = 2;
	int loc = fib[i - 2] + fib[i - 1];
	while (loc <= size + 1) {
		fib.push_back(loc);
		++i;
		loc = fib[i - 2] + fib[i - 1];
	}
	//cout << fib.size()<< endl;
	//for(int i:fib)
	//    cout << i << " ";

	for (auto rit = fib.rbegin(); rit != fib.rend(); ++rit) {
		if (*rit == size + 1)
			return 1;

		if (*rit < size)
			break;
	}

	//cout << endl;
	int count = 0;
	//int re = 0;
	int end = size - 1;
	int min = 0;
	for (end; end >= min; --end) {

		//cout << "end: " << end << " min: " << min << endl;
		if (!A[end]) {
			//cout << i << " ";
			continue;
		}
		//nt loc = end+1;
		//int s = fib.size();


		for (auto rit = fib.rbegin(); rit != fib.rend(); ++rit) {
			//cout << "*rit: " << *rit << " end+1-num: " << end+1-min << endl;
			if (*rit == end + 1 - min) {
				//cout << end+1 << " match" << endl;
				//re = end;
				++count;
				end = size;
				min += (*rit);
				break;
			}

			if (*rit < end + 1 - min) {
				//cout << "b" << endl;
				break;
			}
		}
		//cout << "after" << endl;
		//cout << "end: " << end << " min: " << min << endl;

		//cout << "last: " << end-min+1 << endl;
		int endGame = 0;
		for (auto rit = fib.rbegin(); rit != fib.rend(); ++rit) {
			if (*rit == (end - min + 1)) {
				//cout << "last match: " << *rit << endl;
				++count;
				endGame = 1;
				break;
			}
			if (*rit < (end - min + 1))
				break;
		}
		if (endGame)
			break;

	}
	//cout << "count: " << count << endl;
	if (count)
		return count;

	return -1;
}
