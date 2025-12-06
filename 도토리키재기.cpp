#include <cstdio>
#include <iostream>
#define CRT_SCANF_NO_WARNINGS
using namespace std;

// 시간복잡도: O(n)
int getMaximumHeight(int height[], int month[], int n, int m){
    int maxHeight = -1; // 생일이 n월인 도토리 없을 때, -1

    for(int i = n-1; i >= 0; i--){
        if(month[i] == m){ // 생일 일치
            maxHeight = height[i]; // 최대 키 갱신
            break; // 이후는 실행 안함 > 연산량 감소
        }
    }
    return maxHeight;
}

// 코드 전체의 시간복잡도: O(n)
int main(){
    int n, m; // n: 도토리수, m: 찾으려는 달
    int* height; // height: 도토리의 키
    int* month; // month: 도토리의 출생 월

    scanf("%d", &n);

    height = new int[n];
    month = new int[n];

    // 시간복잡도: O(n)
    for(int i = 0; i < n; i++){ // n개의 도토리 키 입력 받음
        scanf("%d", &height[i]);
    }
    // 시간복잡도: O(n)
    for(int i = 0; i < n; i++){ // n개의 도토리 출생 월 입력 받음
        scanf("%d", &month[i]);
    }

    scanf("%d", &m); // 찾으려는 달 입력 받음

    int answer = getMaximumHeight(height, month, n, m);

    printf("%d\n", answer);

    delete[] height;
    delete[] month;
    return 0;
}