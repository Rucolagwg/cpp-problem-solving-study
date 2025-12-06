#include <cstdio>
#include <vector> // 벡터 컨테이너: 자동으로 메모리가 할당되는 배열이다. vector는 여러가지 멤버함수를 가진다.
#include <algorithm>
using namespace std; // 이걸 쓰면 std::를 안 붙여도 된다. 벡터의 선언은 vector<data type> 변수명

const int MAX_SERIAL_NUMBER = 100000;


void fillFrequencyTable(const vector<int> & data, int n, vector<int> &table) {
    table.clear(); // 테이블 변수에 값이 남아있을 수 있으므로 정리
    table.resize(MAX_SERIAL_NUMBER + 1, 0); // 벡터 크기 조정과 0으로 초기화

    for(int i = 0; i < n; ++i) { // data의 원소를 차례로 조회
        int serial = data[i]; // 시리얼 번호
        table[serial] += 1; // 해당 시리얼 번호의 빈도수 증가
    }
}

vector<int> getUniqueElements(const vector<int>& data, int n) {

    vector<int> ret; // 유일한 원소들 배열, 비어있는 벡터 생성, 배열과 달리 고정사이즈가 아니다.

    // data에 대한 빈도수 테이블 계산
    vector<int> table;
    fillFrequencyTable(data, n, table); 

    for(int number = 1; number <= MAX_SERIAL_NUMBER; number += 1) { // 존재할 수 있는 모든 시리얼 넘버에 대해 차례로 조회.
        
        // 전체 데이터에서 한번만 등장한 number를 차례로 정답 리스트에 추가
        if(table[number] == 1) {
            ret.push_back(number); // ret 마지막에 원소 추가한다.
        }
    }

    return ret; // 오름차순으로 추가했으므로 ret을 정렬할 필요가 없다.
}


int main() {
    int n;
    scanf("%d", &n); // 데이터 수 입력받기

    vector<int> data = vector<int>(n); // 크기 n인 벡터 생성
    for(int i = 0; i < n; ++i){
        scanf("%d", &data[i]); // 시리얼 번호 입력받기
    }

    const vector<int> answer = getUniqueElements(data, n); // 중복 제거된 원소들만 남는다. (배열을 어려우니 벡터를 사용한다.)

    // 각 원소들 출력
    for(int i = 0; i < answer.size(); ++i) {
        if(i > 0) { // 첫 번째 원소가 아니면, 앞에 공백 하나 추가 (첫 번째엔 공백이 필요 없으므로)
            printf(" ");
        }
        printf("%d", answer[i]);
    }

    return 0;
}