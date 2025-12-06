#include <iostream>
#include <queue>
using namespace std;

int maps[10][10] = {0};
int visited[10] = {0};
int num; // 노드 수

void init() { // 그래프 초기화
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maps[i][j] = 0; // 모든 노드 간 연결을 0으로 초기화
        }
    }
}

void dfs(int v) {
    cout << v << endl;
    visited[v] = 0; // 현재 노드 방문 표시를 0으로 변경
    for (int i = 0; i <= num; i++) { // 현재 노드와 연결된 노드를 탐색
        if (maps[v][i] && visited[i]) { // 연결된 노드가 있고 방문하지 않았다면 / visited[i]는 방문하면, 0으로 변경
            dfs(i); // 재귀적으로 dfs 호출
        }
    }
}

int main() {
    int a, b;
    cin >> num;

    init();

    for (int i = 0; i < num; i++) { // 간선 수만큼 반복
        cin >> a >> b;
        maps[a][b] = maps[b][a] = 1; // 양방향 그래프이므로 두 방향 모두 연결
        visited[a] = visited[b] = 1; // 연결된 노드 방문 표시
    }

    dfs(1); // 1번 노드부터 탐색 시작

    return 0;
}