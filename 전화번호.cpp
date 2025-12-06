#include <cstdio>
using namespace std;

const int MAX_TABLE_LENGTH = 10000;

void fillFrequencyTable(int data[], int n, int table[]) {
    // 빈도수 변수 초기화
    int frequent_number = 0;
    for(int i = 0; i < MAX_TABLE_LENGTH; i++) {
        table[i] = 0;
    }
    // 각 전화번호의 빈도수 계산
    for(int i = 0; i < n; i++) {
        frequent_number = data[i];
        table[frequent_number] += 1; // 해당 번호의 빈도수 증가
    }
}

int getFrequentNumber(int data[], int n) { // 가장 많이 나타난 번호 구하기
    int frequent_number = 0;

    int table[MAX_TABLE_LENGTH]; // 전화번호 빈도수 테이블
    fillFrequencyTable(data, n, table);

    for(int i = 0; i < MAX_TABLE_LENGTH; i++) {
        if(table[i] > table[frequent_number]) { // 횟수가 같은 경우 더 작은 번호로 업뎃한다.
            frequent_number = i;
        }
    }

    return frequent_number;
}

int main() {
    int n;
    scanf("%d", &n); // 입력 받을 전화번호 수 입력 받기

    int* data = new int[n]; // 동적 배열 할당
    
    // 입력 받은 수 만큼 전화번호 입력 받기
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    int answer = getFrequentNumber(data, n); // 0 ~ 9999 사이의 수

    printf("%04d", answer); // 0000 ~ 9999 네 자리로 출력

    delete[] data; // 동적 배열 해제
    return 0;
}