#include <iostream>
#define CRT_SCANF_NO_WARNINGS
using namespace std;

int maps[10][10] = {0};
int visited[10] = {0};
int num;

void init() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maps[i][j] = 0;
        }
    }
}

void DFS(int v) {
    cout << v << endl;
    visited[v] = 0;

    for (int i = 0; i <= num; i++) {
        if (visited[i] && maps[v][i]) {
            DFS(i); 
        }
    }
}

int main() {
    int a, b;
    cin >> num;

    init();

    for (int i = 0; i < num; i++) {
        cin >> a >> b;
        maps[a][b] = maps[b][a] = 1;
        visited[a] = visited[b] = 1;
    }

    DFS(1);

    return 0;
}