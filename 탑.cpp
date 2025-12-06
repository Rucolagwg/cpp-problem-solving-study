#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Tower {
public:
    int index; // 타워의 인덱스
    int height; // 타워의 높이
    int targetTowerIndex; // 이 타워의 레이저를 수신하는 타워 인덱스

    Tower(int index, int height) {
        this->index = index; // 타워의 인덱스
        this->height = height; // 타워의 높이
        this->targetTowerIndex = 0; // 기본값 0으로 초기화
    }

    void setTargetTowerIndex(int targetTowerIndex) { // 레이저를 수신하는 타워 인덱스 설정
        this->targetTowerIndex = targetTowerIndex;
    }

    int getTargetTowerIndex() { // 레이저를 수신하는 타워 인덱스 반환
        return this->targetTowerIndex;
    }
};

// 레이저를 수신하는 타워(타겟 타워)를 찾는 함수
void findTargetTowers(vector<Tower>& towers) {
    // 현재 다른 타워의 신호를 수신할 가능성이 있는 타워들
    stack<Tower> stk;

    // 시간복잡도 O(N)
    for(int i = 0; i < towers.size(); i++) {
        Tower& t = towers[i]; // 각 타워 t에 대해 차례로
        int targetTowerIndex = 0; // 타워 t의 레이저를 수신할 후보 (초기값 null)

        // 스택이 비어있지 않고, 스택의 가장 위에 있는 타워의 높이가 t보다 작을 때
        while(stk.empty() == false && stk.top().height < t.height) {
                stk.pop(); // 스택에서 제거
        }

        // t보다 높은 타워가 스택에 남아있다면
        if(stk.size() > 0) {
            // 스택의 가장 위에 있는 타워의 인덱스를 타겟으로 설정
            targetTowerIndex = stk.top().index;
        }

        // 계산한 타겟 정보 저장
        t.setTargetTowerIndex(targetTowerIndex);

        // t는 마지막에 등장 -> 다른 타워의 신호 수신 가능성이 있음.
        stk.push(t); // 스택에 추가
    }
}

int main() {
    int n;
    cin >> n; // 타워의 개수 입력

    vector<Tower> towers; // 타워 객체를 저장할 벡터
    for(int i = 0; i < n; ++i) {
        int hi;
        cin >> hi; // 타워의 높이 입력
        towers.push_back(Tower(i + 1, hi)); // 인덱스는 1부터 시작한다
    }

    // 각 타워가 송신하는 레이저에 대해 타겟을 모두 계산
    findTargetTowers(towers);

    for(int i = 0; i < n; ++i) { // i ++?
        if (i > 0) {
            cout << " "; // 타워 인덱스 사이에 공백 출력
        }
        Tower t = towers[i];
        int targetIndex = t.getTargetTowerIndex();
        cout << targetIndex;
    }

    
    cout << endl; // 마지막에 개행 추가 (일반적인 출력 형식)

    return 0; // main 함수는 int를 반환하므로 return 0; 추가 (표준)
}

/** <스택을 사용하지 않은 풀이법>
 * 시간복잡도: O(N^2)
for(i = 0 ~ N-1) {
    int target = 0;
    for(j = i - 1 ~ 0) {
        if(h[j] > h[i]) {
            target = j;
            break;
        }
    }
}
*/