#include <cstdio>
#include <iostream>
#define CRT_SCANF_NO_WARNINGS
using namespace std;

int getElementTypeCount(int* data, int n){
    int countType = 1;

    for(int i = 1; i < n; i++){ // 1부터 시작해야 i - 1이 0번째 인덱스가 된다.
        if(data[i - 1] != data[i])  // i - 1번째 인덱스와 i번째 인덱스가 다르면 중복이 아니므로 countType에 1씩 추가
            countType++;
    }
    return countType;
}

int main(){
    int n; // n: 화보의 수
    int* data;

    scanf("%d", &n);
    data = new int[n];

    for(int i = 0; i < n; i++){ // 화보의 수만큼 고유번호 입력 받는다
        scanf("%d", &data[i]);
    }

    int answer = getElementTypeCount(data, n);

    printf("%d\n", answer);

    delete[] data;
    return 0;
}