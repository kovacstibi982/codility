﻿#include "GenomicRangeQuery.h"

/*
A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:

	P[0] = 2    Q[0] = 4
	P[1] = 5    Q[1] = 5
	P[2] = 0    Q[2] = 6
The answers to these M = 3 queries are as follows:

The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
Write a function:

vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.

Result array should be returned as a vector of integers.

For example, given the string S = CAGCCTA and arrays P, Q such that:

	P[0] = 2    Q[0] = 4
	P[1] = 5    Q[1] = 5
	P[2] = 0    Q[2] = 6
the function should return the values [2, 4, 1], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [1..50,000];
each element of arrays P, Q is an integer within the range [0..N − 1];
P[K] ≤ Q[K], where 0 ≤ K < M;
string S consists only of upper-case English letters A, C, G, T.
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int getValue(char c) {

	switch (c) {
	case 'A':
		return 1;
	case 'C':
		return 2;
	case 'G':
		return 3;
	case 'T':
		return 4;
	}

	return 0;
}

std::vector<int> GROsolution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
	// write your code in C++14 (g++ 6.2.0)

	std::vector<int> ret(P.size());
	//cout << S << endl;
	auto itQ = Q.begin();
	auto itRet = ret.begin();
	for (auto itP = P.begin(); itP != P.end(); ++itP) {
		int l = *itQ - *itP + 1;
		std::string sub = S.substr(*itP, l);
		int min = 4;
		for (std::string::iterator itS = sub.begin(); itS != sub.end(); ++itS) {
			int minCandidate = getValue(*itS);
			if (minCandidate < min) {
				min = minCandidate;
			}
		}
		*itRet = min;
		++itRet;
		++itQ;
	}

	return ret;
}


std::vector<int> GROsolution02(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
	// write your code in C++14 (g++ 6.2.0)
		std::string nuc = "ACGT";

		int size = P.size();
		std::vector<int> min(size);
		for (int i = 0; i < size; ++i) {
			std::string sub = S.substr(P[i], (Q[i] - P[i]) + 1);
			//cout << sub << endl;
			for (int j = 0; j < 4; ++j) {
				std::size_t found = sub.find(nuc[j]);
				if (found != std::string::npos) {
					min[i] = j + 1;
					//cout << found << endl;
					break;
				}
			}
		}
		return min;
}

std::vector<int> GROsolution03(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
	// write your code in C++14 (g++ 6.2.0)
	std::string nuc = "ACGT";

	int size = P.size();
	std::vector<int> min(size);
	for (int i = 0; i < size; ++i) {
		std::string sub = S.substr(P[i], (Q[i] - P[i]) + 1);
		std::set<char> reduce;
		for (char c : sub)
			reduce.insert(c);
		//cout << sub << endl;
		auto b = reduce.begin();
		for (int j = 0; j < 4; ++j) {
			if (nuc[j] == *b) {
				min[i] = j + 1;
				//cout << found << endl;
				break;
			}
		}
	}
	return min;
}

