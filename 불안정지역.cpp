#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class City {
public:
    int index; // 도시의 인덱스
    int income; // 해당 도시의 소득

    City(int index, int income) {
        this->index = index;
        this->income = income;
    }

    // 대소 관계 추가 (priority_queue에서 사용하기 위함)
    // income 기준으로 정렬. income이 같으면 index는 고려하지 않는다.

    // operator < 는 less<City>가 사용할 때, 기본 priority_queue (max-heap)가 사용할 때 필요.
    // income이 작은게 우선순위가 높게하려면(min-heap처럼) true 반환
    bool operator < (const City& o) const {
        return this->income < o.income; // max-heap: income 큰게 top
    }

    // operator > 는 greater<City>가 사용할 때 필요.
    // income이 큰게 우선순위가 높게하려면(max-heap처럼) true 반환
    bool operator > (const City& o) const {
        return this->income > o.income; // min-heap: income 작은게 top
    }
};


int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
    int answer = 0;

    // 소득이 가장 작은 도시부터 pop되는 우선순위 큐 (min-heap)
    priority_queue<City, vector<City>, greater<City>> rangeMinimum;
    // 소득이 가장 높은 도시부터 pop되는 우선순위 큐 (max-heap)
    priority_queue<City> rangeMaximum;

    // 초기 윈도우 (k-1개) 채우기
    for (int i = 0; i < k - 1; i++) {
        rangeMaximum.push(cities[i]);
        rangeMinimum.push(cities[i]);
    }

    for (int i = k - 1; i < n; i++) {
        rangeMaximum.push(cities[i]);
        rangeMinimum.push(cities[i]);

        // 윈도우 범위를 벗어난 도시들 제거
        // 현재 윈도우의 시작 인덱스는 i - (k - 1) = i - k + 1
        while (rangeMaximum.top().index < i - k + 1) {
            rangeMaximum.pop();
        }
        while (rangeMinimum.top().index < i - k + 1) {
            rangeMinimum.pop();
        }
        // 현재 윈도우 [i-k+1, i]
        answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);
    }

    return answer;
}

void process(int caseIndex) {
    int n, k;
    cin >> n >> k; // 도시의 개수 n, 윈도우 크기 k 입력
    vector<City> cities; // 도시 정보를 저장할 벡터

    for (int i = 0; i < n; i++) {
        int income;
        cin >> income; // 도시의 소득 입력
        cities.push_back(City(i, income)); // 도시의 인덱스를 0부터 n-1로 저장
    }

    int result = getMaximumRangeDifference(n, k, cities);
    cout << result << endl;
}

int main() {
    int caseSize;
    cin >> caseSize; // 테스트 케이스 수 입력
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex);
    }

    return 0;
}