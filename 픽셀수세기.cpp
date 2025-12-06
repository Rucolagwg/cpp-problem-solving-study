#include <cstdio>
#include <iostream>
using namespace std;

bool isInside(long long x, long long y, long long R) {
    long long sqd = x*x + y*y;

    if(sqd < R*R) { // 원의 부등식: x^2 + y^2 < R^2
        return true; // 만족하면 true
    }
    return false;
}


void testcase(int caseIndex) {
    long long R;
    scanf("%lld", &R);

    long long sum = 0; // 1사분면에 존재하는 총 픽셀의 수
    long long y = R;
    for(long x = 0; x <= R; x++) {
        long long height = 0;
        for(; y >= 0; y--) { // 높이를 한칸씩 줄여가면서
            if(isInside(x, y, R)) { // 원 부등식을 만족(좌표가 원 내부에 있다)
                height = (y + 1); // 높이가 y + 1
                break;
            }
        }

        sum += height; // 너비 = 1
    }

    printf("#%d\n", caseIndex);
    printf("%lld\n", sum * 4); // 모든 사분면의 픽셀 수이므로 *4
}

int main() {
    int caseSize;
    scanf("%d", &caseSize); // 테스트 케이스 수 입력 받기
    for(int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        testcase(caseIndex);
    }
    return 0;
}