#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);

        if (s.count(x) > 0) { // set의 count() 메서드를 사용하여 중복 확인
            printf("DUPLICATED\n");
        }
        else {
            s.insert(x); // set에 삽입
            printf("OK\n");
        }
    }

    return 0;
}

