#include <cstdio>
#include <vector>
using namespace std;

// 소인수 분해를 빠르게
class Sieve {
public:
    int maximumValue; // 소수를 판별할 수 있는 최대 값
    vector<bool> isPrime; // 각 숫자별 소수 여부 나타내는 배열

    // 생성자: 최대 값을 받아서 체를 초기화
    Sieve(int maximumValue) {
        this->maximumValue = maximumValue;
        this->isPrime.assign(maximumValue + 1, false); // 모두 false로 초기화
        this->fillSieve(); // 체 알고리즘 실행
    }

    // 소수 판별 함수(소수인지 아닌지 여부 반환)
    bool isPrimeNumber(int num) const {
        return this->isPrime[num];
    }

    // 에라토스테네스의 체 알고리즘을 사용한 소수 찾는 함수
    void fillSieve() {
        isPrime.assign(this->maximumValue, true); // 모든 수를 소수라고 가정
        isPrime[0] = isPrime[1] = false;           // 0과 1은 소수가 아님

        for (int num = 2; num <= maximumValue; num += 1) {
            if (isPrime[num] == false) {
                continue; // 이미 소수가 아님이 판별된 수는 건너뜀
            }

            // num의 배수들은 모두 소수가 아님 > 제거
            for (long long mul = (long long) num * num; mul <= maximumValue; mul += num) {
                int index = (int) mul;
                isPrime[index] = false;
            }
        }
    }
};

// 주어진 범위 [from, to] 내의 모든 소수를 벡터에 담아 반환
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
    vector<int> primes;

    for(int num = from; num <= to; num += 1) {
        if(sieve.isPrimeNumber(num)) {
            primes.push_back(num); // 소수이면 결과에 추가
        }
    }

    return primes;
}

// 각 테스트 케이스에 대해 입력을 받고 결과를 출력
void process(int caseIndex, const Sieve &sieve) {
    int L, R;
    scanf("%d %d", &L, &R); // 구간 [L, R] 입력 받기

    // 구간 내 모든 소수 구하기
    vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);

    // 출력: 케이스 번호와 해당 구간의 소수 개수
    printf("Case #%d:\n", caseIndex);
    printf("%zu\n", allPrimeNumbers.size());
}

int main() {
    const int MAX_VALUE = 1000000; // 전처리. 소수를 구할 최대 값
    Sieve sieve = Sieve(MAX_VALUE); // 전처리. 소수 판별용 체 생성 및 초기화

    int caseSize;
    scanf("%d", &caseSize); // 테스트 케이스 개수 입력 받기

    // 각 케이스에 대해 처리
    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        process(caseIndex, sieve);
    }

    return 0;
}