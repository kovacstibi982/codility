#include <iostream>
#include "MissingInteger.h"
#include "BinaryGap.h"
#include "CyclicRotation.h"
#include "OddOccurrencesInArray.h"
#include "PermMissingElem.h"
#include "FrogJmp.h"
#include "TapeEquilibrium.h"
#include "PermCheck.h"
#include "FrogRiverOne.h"
#include "MaxCounters.h"
#include "GenomicRangeQuery.h"
#include "CountDiv.h"

void BinaryGap();
void CyclicRotation();
void OddOccurrencesInArray();

int main() {

	OddOccurrencesInArray();
	return 0;
}

void MissingInteger() {
	std::vector<int> v{1,2,3,4,6};
	int s = MIsolution(v);
	std::cout << s << std::endl;
}

void BinaryGap() {
	int i = 15;
	int j = 1376796946;
	int r = BGsolution(j);
	// todo: 561892, 74901729, 1376796946
	std::cout << r << std::endl;
}

void CyclicRotation() {
	std::vector<int> A = {};
	int K = 3;
	std::vector<int> rA = CRsolution(A, K);
	// todo: empty vector
}

void OddOccurrencesInArray() {
	std::vector<int> A = { 1, 2, 2, 1, 2, 3, 4, 2, 3 };
	int ret = OOAsolution(A);
	std::cout << ret << std::endl;
}

void PermMissingElem() {
	std::vector<int> v = { 1,2,3,5 };
	int ret = PMEsolution(v);
	std::cout << ret << std::endl;
}

void FrogJmp() {
	// TODO: no jump needed, got 3 expected 2,   got 4 expected 3, got 987654223 expected 987654222, got 1000000000 expected 999999999
	int ret = FJsolution(10, 85, 30);
	std::cout << ret << std::endl;
}

void TapeEquilibrium() {
	// TODO: two elements: got 0 expected 2000; small elements: got 0 expected 20
	std::vector<int> v = { 3,1,2,4,3 };
	int ret = TEsolution(v);
	std::cout << ret << std::endl;
}

void PermCheck() {
	std::vector<int> v = { 4,1,3 };
	int ret = PCsolution(v);
	std::cout << ret << std::endl;
}

void FrogRiverOne() {
	// todo: 
	int X = 5;
	std::vector<int> v = { 1,3,1,4,2,3,5,4 };
	int ret = FROsolution(X, v);
	std::cout << ret << std::endl;
}

void MaxCounters() {

	// TODO: arge random test, 10000 max_counter operations, all max_counter operations
	std::vector<int> v = { 3,4,4,6,1,4,4 };
	int N = 5;
	std::vector<int> ret = MCsolution(N, v);
	for (std::vector<int>::iterator it = ret.begin(); it != ret.end(); ++it)
		std::cout << *it << std::endl;
}

void GenomicRangeQuery() {
	// TODO: GGGGGG..??..GGGGGG..??..GGGGGG, large random string, length, all max ranges
	std::string S = "CAGCCTA";
	std::vector<int> P = { 2, 5, 0 };
	std::vector<int> Q = { 4, 5, 6 };
	std::vector<int> ret = GROsolution(S, P, Q);
	for (std::vector<int>::iterator it = ret.begin(); it != ret.end(); ++it)
		std::cout << *it << std::endl;
}

void CountDiv() {
	//TODO: A = 100, B=123M+, K=2; A = 101, B = 123M+, K = 10K; A = 0, B = MAXINT, K in {1,MAXINT}
	int A = 6, B = 11, K = 2;
	int ret = CDsolution(A, B, K);
	std::cout << ret << std::endl;
}
