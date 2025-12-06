#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

class Histogram {
public:
    int height; // 히스토그램의 높이
    int leftX; // 인덱스 혹은 히스토그램의 왼쪽
    int rightX; // 히스토그램의 오른쪽 변의 X좌표

    Histogram() { }

    Histogram(int index, int height) {
        this->leftX = index;
        this->rightX = this->leftX + 1; // 각 히스토그램의 너비는 1로 가정
        this->height = height;
    }
};

/**
 * 왼쪽에서 오른쪽으로 차례로 세워진 히스토그램들 내부에 만들수 있는 최대 직사각형의 넓이를 구하는 함수
 * @param n: 히스토그램 개수
 * @param histograms: 히스토그램 벡터
 * @return: 최대 직사각형의 넓이
 */
long long getLargestRectangleArea(const vector<Histogram>& histograms) {
    long long answer = 0; // 최대 직사각형의 넓이

    stack<Histogram> stk; // 현재 우측으로 확장 가능성이 있는 히스토그램들

    stk.push(Histogram(-1, 0)); // 편의를 위해 가장 왼쪽에 높이 0의 가상의 히스토그램 추가
    for(int i = 0; i < histograms.size() + 1; i++) {
        // 왼쪽부터 오른쪽 히스토그램까지 차례로
        Histogram h;
        if(i < histograms.size()) {
            h = histograms[i];
        }
        else {
            // if (i == n), 편의를 위해 가장 오른쪽에 높이 0의 가상의 히스토그램 추가
            h = Histogram(histograms.size(), 0);
        }

        // 이전에 확장 중이던 히스토그램들 중, h보다 높은 히스토그램들은 더 확장 불가 (즉, 최대 넓이가 결정)
        while(stk.size() > 1 && stk.top().height > h.height) {
            // 확장 중이던 히스토그램
            Histogram lh = stk.top(); // 삭제하기 전의 top을 나중에 사용하기 위함
            stk.pop();

            // 그 이전의 히스토그램 (왼쪽 확장의 끝)
            Histogram bh = stk.top();

            // 현재 추가된 h의 바로 왼쪽까지 확장중이었다.
            long long width = abs(h.leftX - bh.rightX);
            long long height = lh.height;
            long long area = width * height; // 면적

            answer = max(answer, area); // 최대값 갱신
        }
    
        stk.push(h); // h 새로 추가

    }
    
    return answer;
}

void process(int caseIndex) {
    int n;
    cin >> n; // 히스토그램의 개수 입력

    vector<Histogram> histograms; // 히스토그램 저장할 벡터
    for(int i = 0; i < n; i++) { 
        int height;
        cin >> height; // 각 히스토그램의 높이 입력
        histograms.push_back(Histogram(i, height)); // 히스토그램 객체 생성 후 벡터에 추가
    }

    long long answer = getLargestRectangleArea(histograms); // 최대 직사각형의 넓이 계산
    cout << answer << endl; // 최대 직사각형의 넓이 출력
}

int main() {
    int caseSize;
    cin >> caseSize; // 테스트 케이스 개수 입력

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex); // 각 테스트 케이스 처리
    }
}

/** <3중 반복문>을 이용한 풀이
 * 시간복잡도: O(N^3) --> 스택을 사용하자
 * for(int l = 0 ~ n-1) {
 *    for(int r = l ~ n-1) {
 *       for(int i = l ~ r) {
 *         // 높이 최소값 구하기
 *         // 면적 = (r - l + 1) * min(높이)
 *        }
 *    }
 * }
 */