#include <cstdio>
#include <vector>
using namespace std;

// 자연수 N을 구성하는 모든 소인수를 반환하는 함수
vector<int> factorize(long n) {
    vector<int> factors;

    for(int div = 2; div * div <= n; div += 1) { // sqrt(N) 이하의 자연수 div에 대해
        while(n % div == 0) { // div이 N의 약수라면 > div보다 작은 약수는 모두 처리되었으므로 div는 소인수이다.
            factors.push_back(div); // 소인수 목록에 div 추가
            n /= div; // N을 div를 소거 > 이후엔 div를 제외한 소인수를 찾게 된다.
        }
    }
    if(n > 1) { // 소인수 찾지 못하고 남은 N이 있다면, 그것은 소수이다.
        factors.push_back(n); // 소인수 목록에 추가
    }

    return factors;
}

void process(int caseIndex) {
    int n;
    scanf("%d", &n); // 소인수 분해할 자연수 입력

    vector<int> factors = factorize(n);

    printf("#%d:\n", caseIndex); // 테스트 케이스 번호 출력
    for(int i = 0; i < factors.size(); ++i) {
        if(i > 0) {
            printf(" ");
        }
        printf("%d", factors[i]);
    }
    printf("\n");
}

int main() {
    int caseSize;
    scanf("%d", &caseSize); // 테스트 케이스 수 입력

    for(int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        process(caseIndex); // 케이스 수만큼 반복하며 각 테스트 케이스 처리
    }
}