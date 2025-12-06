#include <iostream>
#include <queue>
using namespace std;

int map[10][10] = {0}; // 그래프를 인접 행렬로 표현
int visit[10] = {0}; // 방문 여부 확인하는 배열
queue<int> q; // 큐를 사용하여 구현
int num, edge_num; // 노드 수, 간선 수

void bfs(int v) {
    cout << v << "\n";
    q.push(v); // 시작 노드를 큐에 넣고 방문 표시
    while(!q.empty()) { // 큐가 비어있지 않을 때까지 반복
        int node = q.front(); // 큐의 맨 앞 노드를 가져옴. 왜냐면, 먼저들어온 노드가 먼저 나와야 하니까
        q.pop(); // 큐에서 제거
        for (int i = 0; i <= num; i++) { // 현재 노드와 연결된 노드를 탐색
            if (map[node][i] == 1 && visit[i] == 0) { 
                visit[node] = 1; // 현재 노드 방문 표시
                visit[i] = 1; // 연결된 노드 방문 표시
                cout << i << endl;
                q.push(i); // 연결된 노드를 큐에 추가
            }
        }
    }
}

int main() {
    cin >> num >> edge_num;
    for (int i = 0; i < edge_num; i++) { // 간선 수만큼 반복
        int a, b;
        cin >> a >> b;
        map[a][b] = map[b][a] = 1; // 양방향 그래프이므로 두 방향 모두 연결한다
    }

    bfs(1); // 1번 노드부터 탐색 시작

    return 0;
}