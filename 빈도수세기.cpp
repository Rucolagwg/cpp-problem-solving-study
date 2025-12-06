#include <stdio.h>
#include <map>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    // 각 <정수, 빈도수> 형태로 key-value를 저장할 Map 자료구조
    // frequencyMap := 이전에 입력된 정수들의 빈도수를 저장하고 있다.

    map<int, int> frequencyMap;

    for (int i = 0; i < N; i++) {
        int X;
        scanf("%d", &X);
        frequencyMap[X]++; // frequencyMap[key]
        printf("%zu %d\n", frequencyMap.size(), frequencyMap[X]); // %zu는 size_t형을 출력하기 위한 형식지정자
    }

    return 0;

    /*
    map<int, int> ::iterator it;

    for(it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
        printf("%d %d\n", it->first, it->second);
    }
    */
}