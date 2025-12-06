#include <cstdio>
#include <iostream>
using namespace std;

void bubbleSort(int data[], int n) {
    for(int i = 0; i < n; i++) {
        int negativecount = 0; // 오름차순이 아닌 쌍의 개수를 세는 변수

        for(int j = 0; j < n - 1 - i; j++) { // 마지막 i개는 이미 정렬되어 있으므로 제외
            // j번째와 j+1번째 값을 비교하여 오름차순이 아닌 경우
            if(data[j] > data[j+1]) { // 오름차순이 아닌 쌍이 나오면 값 2개를 교체한다.
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
                negativecount++;
            }
        }
        
        if(negativecount == 0) // 0이면 멈춘다.
            break;
    }
}

int main() {
    int n; // n: 데이터의 수
    int* data;

    scanf("%d", &n);
    data = new int[n];

    for(int i = 0; i < n; i++) { // n번 반복하며 입력 받기
        scanf("%d", &data[i]);
    }

    bubbleSort(data, n); // 버블정렬 함수 호출

    for(int i = 0; i < n; i++) { // 정렬된 값들 출력
        if(i > 0){
            printf(" ");
        }
        printf("%d", data[i]);
    }

    delete[] data;
    return 0;
}