#include <iostream>
#include <queue>
using namespace std;

int map[10][10] = {0};
int visit[10] = {0};
queue<int> q;
int num, edge_num;

void bfs(int v) {
    cout << v << endl;
    q.push(v);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i <= num; i++) {
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
    for (int i = 0; i < edge_num; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }

    bfs(1);

    return 0;
}