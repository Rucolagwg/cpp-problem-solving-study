#include <cstdio>
#include <iostream>
using namespace std;

bool isConsecutive(int data[], int n) { // 배열의 n개의 원소가 연속적인 정수 수열로 표현될 수 있는지 판단하는 함수
    int max_data = data[0];
    int min_data = data[0];

    // 최대 - 최소 = n - 1
    for(int i = 0 ; i < n; i++) {
        if(max_data < data[i])
            max_data = data[i];
        if(min_data > data[i]) // else를 쓰면 안된다 -> 두 if문은 독립적으로 실행되어야 하기 때문.
            min_data = data[i];
    }

    if(max_data - min_data == n - 1) 
        return true; // 연속적인 수열로 표현 가능
    else
        return false;
}

int main() {
    int n;
    int* data; 

    scanf("%d", &n); // 에피소드 수 입력 받기
    data = new int[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &data[i]); // 에피소드 수만큼 에피소드 번호 입력 받기
    }

    bool result = isConsecutive(data, n);

    if (result) {
        printf("YES"); // 연속적인 수열로 표현이 되면 Yes / 안되면 No
    }
    else {
        printf("NO");
    }

    delete[] data;
    return 0;
}