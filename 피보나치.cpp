#include <cstdio>
#include <vector>
using namespace std;

const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE; // 전역 변수로 선언 (벡터 컨테이너로) > 멤버 함수를 거의 사용하지 않았으므로 굳이 사용할 필요는..
// "메모이제이션" > 중복 계산이 많이 발생할 것 같은 값들을 한 번 계산해두고, 배열과 같은 공간에 저장 후 재사용하는 기법

// 피보나치 수열의 1 ~ n번째 항을 배열에 저장하여 변환해주는 함수
vector<int> makeFibonacciTable(int n) {
    const int MOD = 100000000;

    // 피보나치 배열을 미리 선언
    vector<int> ret(n + 1); // 배열은 0부터, 피보나치 수열은 1부터 시작하므로 n+1 크기로 선언
    ret[1] = 0; // 첫번쨰 항은 0
    ret[2] = 1; // 두번째 항은 1

    // 세번째 항부터는 피보나치의 정의를 이용해 계산
    for(int i = 3; i <= n; ++i) {
        ret[i] = ret[i - 1] + ret[i - 2]; // 피보나치 수열의 정의. f(n) = f(n-1) + f(n-2)
        ret[i] %= MOD; // 모듈러 값을 이용해 뒤에 8자리만 남게 한다. ((A % MOD)) + ((B % MOD)) % MOD == (A + B) % MOD
    }

    return ret;
}


int getFibo(int n) {
    // 피보나치의 값을 미리 계산했으므로 그 값을 반환
    // 첫 항의 인덱스가 0이므로 -1을 해준다
    int answer = FIBONACCI_TABLE[n];

    return answer;
}


int main() {
    FIBONACCI_TABLE = makeFibonacciTable(MAX_N); // "전처리"를 통해 미리 계산

    int caseSize;
    scanf("%d", &caseSize);

    for(int caseIndex = 1; caseIndex <= caseSize; ++caseIndex){
        int n;
        scanf("%d", &n);

        // 피보나치 수열의 n번째 항 계산 후 출력
        int answer = getFibo(n);
        printf("%d\n", answer);
    }

    FIBONACCI_TABLE.clear(); // 배열 할당 해제 (습관을 들이자!)

    return 0;
}