#include <iostream>
#define CRT_SCANF_NO_WARNINGS
using namespace std;

void bubbleSort(int data[], int n) {
    for (int i = 0; i < n; i++) {
        int notcount = 0;
        for (int j = 0; j = n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                notcount++;
            }
        }
        if (notcount == 0) {
            break;
        }
    }
}

int main() {
    int n;
    int* data;

    cin >> n;
    data = new int[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }

    bubbleSort(data, n);

    for (int j = 0; j < n; j++){
        printf("%d ", data[j]);
    }

    delete[] data;

    return 0;
}