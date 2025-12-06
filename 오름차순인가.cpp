#include <iostream>
#define CRT_SCANF_NO_WARNINGS
using namespace std;

bool isOrdered(int data[], int n){
    for(int i = 0; i < n - 1; i++){
        if(data[i] > data[i + 1]){
            return false;
            break; // 오름차순이 아니라면, false를 반환하고 반복문 종료 > 연산량 감소
        }
    }
    return true;
}
// 영상에선 count 변수를 추가해서 count가 0이면 YES, 0보다 크면(=1) NO를 출력하도록 했다.
// (오름차순이 아닌 경우 발생시 반복문 종료하므로 1보다 클 순 없다.)


int main(){
    int n; // n: 학생의 수
    int* data;

    cin >> n; // 학생의 수를 입력 받는다.
    data = new int[n];

    for(int i = 0; i < n; i++){ // 학생의 수만큼 반복하며, 키를 입력 받는다.
        scanf("%d", &data[i]);
    }

    bool result = isOrdered(data, n);

    if (result){ // result가 true일 때, (여기서 true는 오름차순으로 정렬되어있음을 의미)    
        printf("YES");
    } else { // result가 false일 때,
        printf("NO");
    }

    delete[] data;
    return 0;
}