#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

class Player {
public:
    int index;

    Player(int idx = 0) { // 생성자 파라미터 이름을 멤버 변수와 다르게 하여 명확성 증가
        this->index = idx;
    }
};

/**
 * 조세퍼스 게임을 수행하여 각 플레이어가 제거된 순서를 리스트로 반환하는 함수
 * @param n 플레이어 수
 * @param m 매 턴마다 m번째 사람을 제거 (즉, m-1 명을 건너뜀)
 * @param initialPlayers 좌석에 앉아있는 순서대로 주어지는 플레이어 정보
 * @return 제거된 플레이어 순서 리스트
 */
vector<Player> getDeadPlayersList(int n, int m, const vector<Player>& initialPlayers) {
    // 현재 게임에서 제외된 플레이어들의 리스트
    vector<Player> deadPlayersResult; // 함수 내 지역 변수 이름 변경 (testcase의 변수와 구분)
    
    // 아직 게임에서 제외되지 않은 플레이어들의 리스트 (큐 사용)
    queue<Player> que;

    // 큐에 초기 플레이어들을 넣는다.
    // initialPlayers는 n개의 요소를 가지고 있음
    for (int i = 0; i < n; i += 1) { 
        que.push(initialPlayers[i]); // ex: 1 2 3 4 5 6 7
    }

    // 모든 플레이어가 제외될 때까지 반복 (n명의 플레이어가 있으므로 n번 반복)
    for (int i = 0; i < n; i++) {
        if (que.empty()) { // 이론적으로 이 루프 조건(i < n) 하에서는 발생하지 않아야 함
            break;
        }

        // (m-1)명의 사람을 건너뛴다. (큐의 앞에서 빼서 뒤로 넣음)
        // 가령 m=3이면, 2명을 건너뛰고 3번째 사람을 선택.
        // 건너뛸 횟수: (m-1) % 현재 큐 크기
        int skip = (m - 1) % que.size();

        for (int j = 0; j < skip; j += 1) {
            Player p = que.front();
            que.pop();
            que.push(p); 
            // 예: m=3, que: 1 2 3 4 5 6 7. skip = 2.
            // j=0: p=1, que: 2 3 4 5 6 7 1
            // j=1: p=2, que: 3 4 5 6 7 1 2
        }
        
        // m번째 사람은 게임에서 제외한다.
        Player dead = que.front();
        que.pop();

        // 제외 리스트에 추가한다.
        deadPlayersResult.push_back(dead);
    }

    return deadPlayersResult;
}

void testcase(int caseIndex) { // caseIndex는 현재 코드에서 사용되지 않음
    int n, m;
    scanf("%d%d", &n, &m);

    vector<Player> players;
    // 플레이어 초기화 (1부터 n까지의 인덱스)
    for (int i = 0; i < n; i++) {
        players.push_back(Player(i + 1));
    }

    vector<Player> deadPlayers = getDeadPlayersList(n, m, players);

    // 결과 출력
    for (int i = 0; i < deadPlayers.size(); i++) { // deadPlayers.size()는 n과 같다
        if (i > 0) {
            printf(" ");
        }
        // Player p = deadPlayers[i]; // 직접 접근 가능
        printf("%d", deadPlayers[i].index);
    }

    printf("\n");
}

int main() {
    int caseSize;
    scanf("%d", &caseSize); // 테스트 케이스 수 입력

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        testcase(caseIndex); // 테스트 케이스 실행
    }

    return 0;
}