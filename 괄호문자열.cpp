#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Parenthesis {
public:
    bool type; // 열린 괄호면 true, 닫힌 괄호면 false
    int index; // 해당 괄호의 인덱스

    Parenthesis(int index, bool type) {
        this->index = index;
        this->type = type;
    }

    Parenthesis(int index, char c) {
        this->index = index;
        if (c == '(') {
            this->type = true; // 열린 괄호
        } else {
            this->type = false; // 닫힌 괄호
        }
    }
};


/**
 * @brief 주어진 괄호 문자열이 올바른지 확인하는 함수
 * @param n 괄호 문자열의 길이
 * @param parentheses 괄호 문자에 대한 정보가 담긴 벡터
 * @return 올바른 괄호 문자열이면 true, 아니면 false
 */
bool isValidParentheses(const vector<Parenthesis>& parentheses) {
    // 현재 짝을 찾지 못한 열린 괄호들만 저장하는 스택
    // 닫힌 괄호가 나올 때, 탑에 저장된 열린 괄호 삭제
    // 탑 원소 삭제만 하면 되므로, 스택을 사용
    stack<Parenthesis> st;

    for(int i = 0; i < parentheses.size(); i++) {
        // 왼쪽부터 오른쪽의 괄호를 확인
        // 벡터 변수이므로 모든 원소 접근이 가능
        Parenthesis p = parentheses[i];

        if (p.type == true) { // 열린 괄호인 경우
            st.push(p); // 짝 찾을 때 까지 스택에 추가
        }
        else { // 닫힌 괄호인 경우
            if (st.size() > 0) { // 가장 마지막에 추가된 열린 괄호와 짝을 맞출 수 있으므로 제거
                st.pop();
            }
            else { // 짝을 찾지 못한 경우
                return false; // 올바르지 않은 괄호 문자열
            }
        }
    }

    if (st.size() > 0) { // 스택에 남아있는 열린 괄호가 있는 경우
        return false;
    }
    return true;
}

void process(int caseIndex) {
    // 괄호 문자열 입력받기. 길이 n. 벡터에 저장
    string str;
    cin >> str;

    vector<Parenthesis> parentheses;
    // 벡터는 동적 배열(모든 위치의 원소 접근 가능)
    // 스택은 탑 위치의 원소만 접근 가능
    for(int i = 0; i < str.length(); ++i) {
        parentheses.push_back(Parenthesis(i, str[i])); // 괄호 문자와 인덱스 저장
    }

    bool isValid = isValidParentheses(parentheses); // 올바른 괄호 문자열인지 확인

    if(isValid) {
        cout << "YES" << endl; // 올바른 괄호 문자열
    }
    else {
        cout << "NO" << endl; // 올바르지 않은 괄호 문자열
    }
}

int main() {
    int caseSize;
    cin >> caseSize; // 테스트 케이스 개수 입력받기

    for(int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex); // 각 테스트 케이스 처리
    }
}