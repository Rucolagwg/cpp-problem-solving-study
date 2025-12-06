#include <iostream>
#include <queue>
#define CRT_SCANF_NO_WARNINGS
using namespace std;

int maps[10][10] = {0};
int visited[10] = {0};
int num, edge_num;
queue<int> q;

void BFS(int v) {
    cout << v << endl;
    q.push(v);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < num; i++) {
            if (maps[node][i] == 1 && visited[i] == 0) { // 현재 노드와 연결된 노드가 있고 방문하지 않았다면
                visited[node] = 1; // 현재 노드 방문 표시
                visited[i] = 1; // 연결된 노드 방문 표시
                cout << i << endl;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> num >> edge_num;
    for(int i = 0; i < edge_num; i++) {
        int a, b;
        cin >> a >> b;
        maps[a][b] = maps[b][a] = 1;
    }

    BFS(1);

    return 0;
}