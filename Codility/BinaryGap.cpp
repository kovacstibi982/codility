#include "BinaryGap.h"

/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int BGsolution(int N) {
	// write your code in C++14 (g++ 6.2.0)
	int BG = 0;
	std::string binary = "";
	int n = N;
	while (n != 0) {
		if (n % 2)
			binary += "1";
		else
			binary += "0";
		n /= 2;
	}
	int local = 0;
	for (std::string::reverse_iterator it = binary.rbegin(); it != binary.rend(); ++it) {

		if (*it == '0') {
			++local;

		}
		else {
			if (local > BG) {
				BG = local;
			}
			local = 0;
		}

	}

	return BG;
}