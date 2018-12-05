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
#include "PassingCars.h"
#include "MinAvgTwoSlice.h"
#include "Distinct.h"
#include "Triangle.h"
#include "MaxProductOfThree.h"
#include "NumberOfDiscIntersections.h"
#include "Brackets.h"
#include "Nesting.h"
#include "StoneWall.h"
#include "Fish.h"
#include "EquiLeader.h"
#include "Dominator.h"
#include "MaxSliceSum.h"
#include "CountFactors.h"
#include "MinPerimeterRectangle.h"
#include "Peaks.h"
#include "Flags.h"
#include "CountNonDivisible.h"
#include "CountSemiprimes.h"
#include "ChocolatesByNumbers.h"
#include "CommonPrimeDivisors.h"

void BinaryGap();
void CyclicRotation();
void OddOccurrencesInArray();

int main() {

	
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

void PassingCars() {
	std::vector<int> v1 = { 0,1,0,1,1 };
	std::vector<int> v2 = { 1,0,1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,1,1,0,1,0 };
	int ret = PCarsolution(v2);
	std::cout << ret << std::endl;
}

void MinAvgTwoSlice() {
	std::vector<int> v = { 4,2,2,5,1,5,8 };
	int ret = MATSsolution(v);
	std::cout << ret << std::endl;
}

void Distinct() {
	std::vector<int> v = { 1,2,3,2,1 };
	int ret = Dsolution(v);
	std::cout << ret << std::endl;
}

void Triangle() {
	std::vector<int> v = { 1,2,4,5,8,10,20 };
	int ret = Tsolution(v);
	std::cout << ret << std::endl;
}

void MaxProductOfThree() {
	//todo: For example, for the input [-5, 5, -5, 4] the solution returned a wrong answer (got -100 expected 125).
	std::vector<int> v = { -3,1,2,-2,5,6 };
	int ret = MPOTsolution(v);
	std::cout << ret << std::endl;
}

void NumberOfDiscIntersections() {
	std::vector<int> v = { 1,5,2,1,4,0 };
	int ret = NODIsolution(v);
	std::cout << ret << std::endl;
}

void Brackets() {
	std::string S = "[]{}({}[]({}[]({}[]())))";
	int ret = Bsolution(S);
	std::cout << ret << std::endl;
}

void Nesting() {
	std::string S = "()(()(()(()(()(())))))";
	int ret = Nsolution(S);
	std::cout << ret << std::endl;
}
	
void StoneWall() {
	std::vector<int> v = { 8,8,5,7,9,8,7,4,8 };
	int ret = SWsolution(v);
	std::cout << ret << std::endl;
}

void Fish() {
	std::vector<int> A = { 4,3,2,1,5 };
	std::vector<int> B = { 0,1,0,0,0 };
	int ret = Fsolution(A, B);
	std::cout << ret << std::endl;
}

void EquiLeader() {
	std::vector<int> v = { 4,3,4,4,4,2 };
	int ret = ELsolution(v);
	std::cout << ret << std::endl;
}

void Dominator() {
	std::vector<int> v = { 3,4,3,2,3,-1,3,3 };
	int ret = DomSolution(v);
	std::cout << ret << std::endl;
}

void MaxSliceSum() {
	std::vector<int> v = { 3,2,-6,4,0 };
	int ret = MSSsolution(v);
	std::cout << ret << std::endl;
}

void CountFactors() {
	int i = 24;
	int ret = CFsolution(i);
	std::cout << ret << std::endl;
}

void MinPerimeterRectangle() {
	int i = 30;
	int ret = MPRsolution(i);
	std::cout << ret << std::endl;
}

void Peaks() {
	std::vector<int> v = { 1,2,3,4,3,4,1,2,3,4,6,2 };
	int ret = Psolution(v);
	std::cout << ret << std::endl;
}

void Flags() {
	std::vector<int> v = { 1,5,3,4,3,4,1,2,3,4,6,2 };
	int ret = Flagsolution(v);
	std::cout << ret << std::endl;
}

void CountNonDivisible() {
	std::vector<int> v = { 3,1,2,3,6 };
	std::vector<int> ret = CNDsolution(v);
	for (int r : ret)
		std::cout << r << " ";
}

void CountSemiprimes() {
	int N = 26;
	std::vector<int> P = { 1,4,16 };
	std::vector<int> Q = { 26,10,20 };
	std::vector<int> ret = CSsolution(N, P, Q);
	for (int sp : ret)
		std::cout << sp << std::endl;
}

void ChocolatesByNumbers() {
	int N = 10;
	int M = 4;
	int ret = CBNsolution(N, M);
	std::cout << ret << std::endl;
}

void CommonPrimeDivisors() {
	std::vector<int> A = { 15,10,3 };
	std::vector<int> B = { 75,30,5 };
	int ret = CPDsolution(A, B);
	std::cout << ret << std::endl;
}
