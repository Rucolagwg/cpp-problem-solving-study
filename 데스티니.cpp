#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;

class Point2D {
private:
    int x;
    int y;

public:
    Point2D(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // 2차원 평면 상에서 점 this부터 점 target까지 거리의 제곱을 계산하는 함수
    int getSquaredDistanceTo(const Point2D &target) const {
        int dx = abs(this->x - target.x); // abs는 절대값
        int dy = abs(this->y - target.y);

        return dx*dx + dy*dy; // 거리의 제곱 반환
    }

    double getDistanceTo(const Point2D &target) const {
        double sqd = (double) this->getSquaredDistanceTo(target);
        return sqrt(sqd);
    }
};

int main() {
    int n;
    Point2D *points;

    scanf("%d", &n); // 천체의 수 입력 받는다.
    points = new Point2D[n]; // points 배열 선언

    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y); // 좌표값 입력 받는다.

        points[i] = Point2D(x, y); // points 배열에 좌표 저장
    }

    int min_sqd = INT_MAX;
    int min_cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){ // j < i로 해야 중복 없이 반복.
            int sqd = points[i].getSquaredDistanceTo(points[j]);
            if(sqd < min_sqd){ // sqd가 min_sqd보다 작으면
                min_sqd = sqd; // min_sqd를 sqd로 업데이트
                min_cnt = 1; // 카운트도 1로 업데이트
            }
            else if(sqd == min_sqd){ // 같으면
                min_cnt++; // 1씩 증가
            }
        }
    }
    
    double distance = sqrt(min_sqd); // 루트 값은 소수점으로 나오므로, double 사용
    printf("%.1f\n", distance); // 소수점 첫째 자리까지 거리를 출력
    printf("%d\n", min_cnt);

    delete[] points;
    return 0;
}