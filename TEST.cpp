// 소수세기(에라토스테네스의 체)
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void process(int caseIndex,  const Sieve &sieve) {
    int L, R;
    cin >> L >> R;

    vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);

    printf("Case #%d:\n", caseIndex);
    printf("%zu\n", allPrimeNumers.size());
}


int main() {
    const int MAX_VALUE = 1000000;
    Sieve sieve = Sieve(MAX_VALUE);

    int caseSize;
    cin >> caseSize;

    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        process(caseIndex, sieve);
    }

    return 0;
}