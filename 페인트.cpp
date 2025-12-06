#include <cstdio>
#include <vector>
using namespace std;

const int MAX_SEAT_NUMBER = 1000;
const int MAX_COLOR_NUMBER = 100;

// 좌석들을 한 번 색칠하는 이벤트에 대한 정보
class Painting {
public:
    int left;
    int right;
    int color;

    Painting() { }

    Painting(int left, int right, int color) {
        this->left = left;
        this->right = right;
        this->color = color;
    }
};


// data[0] ~ data[n-1]에 등장한 번호들에 대한 빈도수를 채우는 함수
// param table - table[x] := data 배열에서 x가 등장한 횟수
void fillFrequencyTable(int data[], int n, int table[]) {
    for(int i = 0; i < MAX_COLOR_NUMBER; i++) {
        table[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        int color = data[i];
        table[color] += 1;
    }
}


void solve(int n, int m, const Painting* paintings) {
    int* seats = new int[n];
    for (int i = 0; i < n; i++) { // 처음 좌석은 전부 0번 색으로 칠해져 있다.
        seats[i] = 0;
    }

    // 색 정보들이 주어진 순서대로 각 좌석을 색칠한다.
    for(int i = 0; i < m; i++) {
        const Painting &p = paintings[i]; // 모든 색칠 정보 p에 대해 차례로
        for(int j = p.left; j <= p.right; j++) { // 색칠 정보에 따라 좌석의 색을 업뎃
            seats[j] = p.color;
        }
    }

    // 모든 색칠을 완료한 이후 색 정보를 사용 > 모든 색에 대한 빈도수 테이블 계산
    int *table = new int[MAX_COLOR_NUMBER];
    fillFrequencyTable(seats, n, table);

    int minColor = seats[0]; // 가장 적게 등장한 색
    int maxColor = seats[0]; // 가장 많이 등장한 색

    for(int color = 0; color < MAX_COLOR_NUMBER; color += 1) {
        if(table[color] == 0) { // 색상 color가 등장하지 않았다면
            continue;
        }

        // 한 번 이상 등장한 모든 색상에 대해
        if(table[minColor] > table[color]) { // 가장 적게 등장한 색이 아직 없거나, color가 더 적게 등장한 경우
            minColor = color;
        }
        if(table[maxColor] < table[color]) { // 가장 많이 등장한 색이 아직 없거나, color가 더 많이 등장한 경우
            maxColor = color;
        }
    }

    printf("%d\n", maxColor);
    printf("%d\n", minColor);

    delete[] seats;
}


int main() {
    int n, m; // N: 좌석의 수, M: 색칠할 방법의 수
    scanf("%d %d", &n, &m); // 좌석의 수와 색칠할 방법의 수를 입력받는다

    // paintings[i] := i번째에 일어난 색칠 이벤트의 정보
    Painting* paintings = new Painting[m];

    for (int i = 0; i < m; ++i) { // m줄에 걸쳐서 공백으로 구분된 세 정수 입력 받는다.
        scanf("%d", &paintings[i].left);
        scanf("%d", &paintings[i].right);
        scanf("%d", &paintings[i].color);

        // 좌석의 번호는 1번부터 시작하므로, 0 ~ (n-1) 범위로 맞추기 위해 -1씩 빼준다
        paintings[i].left -= 1;
        paintings[i].right -= 1;
    }

    // 문제의 정답을 구한다
    solve(n, m, paintings);

    delete[] paintings;
    return 0;
}