#include <cstdio>
#include <vector>
using namespace std;

class TicketTable {
public:
    vector<bool> used; // 티켓 사용 여부
    int length;

    TicketTable(int length) {
        this->length = length;
        this->used.assign(length, false); 
    }
    
    // 사용자의 회원 번호로 지급받게 될 항공권 번호를 계산하는 메소드
    int findEmptyIndexByUserId(int userId) {
        int index = userId % length; // 맨 처음 시도할 티켓 번호
        while (this->isEmpty(index) == true) { // 사용한 티켓 번호면 스킵
            index = (index + 1) % length; // 다음 티켓 번호로 이동
        }
        return index; // 사용 가능한 티켓 번호 반환
    }

    // 해당 항공권 번호가 이미 사용 중인지 여부를 반환하는 메소드
    bool isEmpty(int ticketIndex) {
        return this->used[ticketIndex]; // 사용 여부 <==> used[ticketIndex]
    }

    // 티켓 사용 여부를 갱신하기 위한 메소드
    void setUsed(int index, bool status) {
        this->used[index] = status;
    }
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) {
    vector<int> tickets; // 티켓 번호를 저장할 벡터
    TicketTable table = TicketTable(n); // 티켓 테이블 생성

    for(int i = 0; i < m; i++) {
        int userId = ids[i]; // 요청 고객의 회원 번호
        int ticketIndex = table.findEmptyIndexByUserId(userId);
        tickets.push_back(ticketIndex); // 티켓 번호 저장
        table.setUsed(ticketIndex, true); // 사용 여부 갱신
    }

    return tickets;
}

int main() {
    // n: 전체 티켓의 수
    // m: 요청 고객의 수
    int n, m;
    scanf("%d %d", &n, &m); // n: 전체 행운권(티켓) 수, m: 입장할 회원 수 입력

    vector<int> ids(m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &ids[i]); // 회원 번호 입력
    }

    vector<int> tickets = getTicketNumbers(n, m, ids);
    for(int i = 0; i < tickets.size(); ++i) {
        printf("%d\n", tickets[i]);// 티켓 번호 출력
    }

    return 0;
}