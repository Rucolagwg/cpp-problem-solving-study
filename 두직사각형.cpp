#include <iostream>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb) {
    int l, r, t, b; // 교차 영역의 좌표
    l = max(la, lb);
    r = min(ra, rb);
    t = min(ta, tb);
    b = max(ba, bb);

    if (l <= r && b <= t) { // 교차 영역이 존재하면
        return ((r - l) * (t - b)); // 넓이 계산한 값 반환
    }

    return 0;
}


void test_case() {
    // 직사각형 a, b의 좌표
    int ax, ay, bx, by;
    int px, py, qx, qy;
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    scanf("%d %d %d %d", &px, &py, &qx, &qy);

    int la, ra, ba, ta; // 직사각형 a
    la = min(ax, bx);
    ra = max(ax, bx);
    ta = max(ay, by);
    ba = min(ay, by);

    int lb, rb, bb, tb; // 직사각형 b
    lb = min(px, qx);
    rb = max(px, qx);
    tb = max(py, qy);
    bb = min(py, qy);

    int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb); // 교차 영역 넓이 계산

    printf("%d\n", answer); // 교차 영역 넓이 출력
}

int main() {
    int t; // 테스트 케이스 수
    scanf("%d", &t); // 테스트 케이스 수 입력

    for(int i = 0; i < t; i++)
        test_case(); // 각 테스트 케이스에 대해 함수 호출

    return 0;
}