#include <iostream>
#include <queue>
using namespace std;

int maps[10][10] = {0};
int visited[10] = {0};
int num; 

void init() { // 초기 상태
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maps[i][j] = 0; // 모든 노드 0으로 초기화
        }
    }
}

void dfs(int v) {
    cout << v << endl;
    visited[v] = 0;
    for (int i = 0; i <= num; i++) {
        if (maps[v][i] && visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int a, b;
    init();
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> a >> b;
        maps[a][b] = maps[b][a] = 1; // 양방향 그래프이니 두 방향 모두 연결
        visited[a] = visited[b] = 1; // 연결된 노드 방문 표시
    }

    dfs(1); // 1번 노드부터 탐색

    return 0;
}