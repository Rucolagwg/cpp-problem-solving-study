#include <iostream>
#define CRT_SCANF_NO_WARNINGS
using namespace std;

bool isOrdered(int data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if(data[i] > data[i + 1]) {
            return false;
            break;
        }
        // return true; 여기가 아니라 for문 바깥에
    }
    return true;
}

int main() {
    int n;
    int* data;

    cin >> n;

    data = new int[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    bool result = isOrdered(data, n);

    if (result) {
        printf("YES");
    }
    else {
        printf("No");
    }

    delete[] data;
    
    return 0;
}