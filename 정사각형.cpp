#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

class Point2D {
public:
    int x;
    int y;
    int index; // 점의 인덱스

    Point2D(int index, int x, int y) { // 인덱스와 좌표를 받아 생성
        this->index = index;
        this->x = x;
        this->y = y;
    }

    Point2D(int x, int y) { // 인덱스 없이 생성
        this->index = 1;
        this->x = x;
        this->y = y;
    }

    long long getSquaredDistanceTo(Point2D target) {
        // 두 좌표간의 제곱거리를 계산
        long long dx = abs(this->x - target.x);
        long long dy = abs(this->y - target.y);

        return dx * dx + dy * dy;
    }

    bool operator < (const Point2D& other) const {
        // 각 좌표의 우선순위를 비교하기 위한 비교 연산자

        // x좌표가 다르다면 x좌표를 기준으로 비교한다.
        if (this->x != other.x) {
            return this->x < other.x;
        }

        // x좌표가 같다면 y좌표를 기준으로 비교한다.
        return this->y < other.y;
    }

};

long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
    long long answer = 0;

    // 모든 점을 Set에 저장한다.
    set<Point2D> pSet; // default::less(오름차순), datatype이 class이므로 대소 관계 정의 필요
    for (int i = 0; i < n; i += 1) {
        pSet.insert(points[i]);
    }

    // 임의의 a와 b 두 점을 잡는다.
    for (int i = 0; i < n; i += 1) {
        Point2D pa = points[i];

        for (int j = 0; j < n; j += 1) {
            Point2D pb = points[j];

            if (i==j) continue; // 같은 점은 제외

            // 두 기준점 pa와 pb를 지정. 선분 pa-pb가 정사각형의 한 변이라고 하자. 
            // 두 점의 거리(선분의 길이)의 제곱 == 정사각형 넓이
            long long area = pa.getSquaredDistanceTo(pb);

            // 이미 계산한 것보다 넓이가 작다면 건너뛰기
            if (area < answer)
                continue;

            // pa->pb 방향의 x, y 좌표에 대한 거리 계산
            int dx = pb.x - pa.x;
            int dy = pb.y - pa.y;

            // 벡터 <dx, dy>를 90도로 회전시키면 <-dy, dx>가 된다.
            // pa와 pb에 벡터 <-dy, dx>를 각각 더해 정사각형을 구성하는 두 점 pd, pc를 계산할 수 있다.
            Point2D pd(pa.x - dy, pa.y + dx);
            Point2D pc(pb.x - dy, pb.y + dx);

            // pd, pc와 결정적이므로 이 점이 pSet에 존재하는 점인지 검사하면 된다.
            if (pSet.count(pc) > 0 && pSet.count(pd) > 0) { // (O(log2N)
            // if (pSet.find(pc) != pSet.end() && pSet.find(pd) != pSet.end()) {
                answer = max(answer, area);
            }
        }
    }

    return answer;
}

void process(int caseIndex) {
    int n;
    cin >> n; // 점의 개수 입력

    vector<Point2D> points; // 점을 저장할 벡터

    for (int i = 0; i < n; i += 1) {
        int x, y;
        cin >> x >> y; // 각 점의 좌표 입력
        points.push_back(Point2D(i, x, y)); // Point2D 객체 생성 후 벡터에 추가
    }

    double answer = getMaximumSquareArea(n, points); // 최대 정사각형 넓이 계산

    cout << fixed << setprecision(2) << answer << endl; // 소수점 둘째자리까지 출력
}

int main() {
    int caseSize;
    cin >> caseSize; // 테스트 케이스의 개수 입력

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex); // 각 테스트 케이스 처리
    }
}