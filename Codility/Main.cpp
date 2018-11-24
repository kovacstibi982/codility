#include <iostream>
#include "MissingInteger.h"
#include "BinaryGap.h"
#include "CyclicRotation.h"
#include "OddOccurrencesInArray.h"
#include "PermMissingElem.h"
#include "FrogJmp.h"
#include "TapeEquilibrium.h"

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
	int r = BGsolution(i);
	// todo: 561892, 74901729, 1376796946
	std::cout << r << std::endl;
}

void CyclicRotation() {
	std::vector<int> A = { };
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
