#include <cstdio>
#include <iostream>
using namespace std;

bool isPrime(int N) { // 소수 판별 함수
    if(N == 1) return false; // 1은 소수가 아니므로 false

    for(int i = 2; i * i <= N; i++) { // 반복하면서 약수의 개수를 센다 (i는 루트 n까지 반복한다. > 시간 복잡도 감소)
        if(N % i == 0) // 약수가 존재하므로 false
            return false;
    }

    return true;
}

void testcase(int caseIndex) {
    int n; // n: 수정이가 정한 숫자
    scanf("%d", &n); // 소수인지 판별할 숫자 입력

    bool result = isPrime(n); // 소수 판별 함수를 통해 result가 true나 false로 저장

    printf("Case #%d\n", caseIndex); // 케이스 번호 출력
    if(result) { // result가 true일 때,
        printf("YES\n"); // YES 출력
    }
    else { // false일 때,
        printf("NO\n"); // NO 출력
    }
}

int main(){
    int caseSize; // caseSize: 테스트 케이스 수
    scanf("%d", &caseSize); // 테스트 케이스의 수를 입력 받는다.

    for(int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) { // 입력받은 케이스 수만큼 반복하며 소수 여부를 출력
        testcase(caseIndex); // 소수 판별 함수 호출
    }

    return 0;
}