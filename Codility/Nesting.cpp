#include "Nesting.h"

/*
A string S consisting of N characters is called properly nested if:

S is empty;
S has the form "(U)" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:

int solution(string &S);

that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..1,000,000];
string S consists only of the characters "(" and/or ")".
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int Nsolution(std::string &S) {
	// write your code in C++14 (g++ 6.2.0)
	std::stack<char> s;

	for (char c : S) {
		if (c == '(')
			s.push(c);
		else {
			if (!s.empty()) {
				char rc = s.top();
				s.pop();
				if (rc != '(')
					return 0;
			}
			else
				return 0;
		}
	}

	if (s.empty())
		return 1;
	else
		return 0;

	return 0;
}
