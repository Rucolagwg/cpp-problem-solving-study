#include <stdio.h>
#include <vector>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/**
* 중복을 포함해 두 카드의 합으로 만들 수 있는 당첨번호의 수를 계산하는 함수
* @param n 카드의 수
* @param m 검사하려는 당첨번호의 수
* @param cards 각 카드에 적힌 숫자들
* @param target 검사하려는 각 당첨번호 리스트
* @return 가능한 당첨번호 리스트
*/

vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
    vector<int> possibleTargets; // 만들 수 있는 당첨 번호들
    
    // 모든 카드 오름차순 정렬 (이진 탐색 조건)
    sort(cards, cards + n);

    for(int i = 0; i < m; ++i) {
        int k = targets[i]; // 모든 타겟 k에 대해
        bool possible = false; // 가능한 조합이 존재하는지 확인하기 위함

        // 카드의 합이 target이 되는지 확인
        for(int j = 0; j < n; ++j) {
            int x = cards[j]; // 모든 카드 중 하나인 x에 대해

            for(int p = 0; p <= j; p += 1)  {// 숫자 조합 중복 없애기
                int y = cards[p]; // 카드 중 하나인 y 선택
                int z = k - (x + y); // k = (x + y) + z가 되는 z 계산
                
                // z가 카드에 존재하는지 
                if(binary_search(cards, cards + n, z) == true) { // 시작점, 끝 지점, 찾고자 하는 값
                    possible = true; // 가능한 조합이 존재
                    break;
                }
            }
            if(possible) { // 존재하면 더 이상 탐색할 필요가 없다
                break;
            }
        }

        if(possible) {
            possibleTargets.push_back(k); // 가능한 조합이 존재하면 k를 추가
        }
    }

    sort(possibleTargets.begin(), possibleTargets.end()); // 오름차순 정렬
    return possibleTargets;
}


int main() {
    int n; // 카드 수
    int m; // 검사할 후보 당첨번호의 수
    scanf("%d %d", &n, &m);
   
    int* cards = new int[n]; // 카드 번호 배열 동적 할당
    int* targets = new int[m]; // 당첨 번호 배열 동적 할당
   
    // 각 카드 정보 입력받기
    for(int i = 0; i < n; i++){
        scanf("%d", &cards[i]);
    }
   
    // 각 후보 당첨번호 입력받기
    for(int i = 0; i < m; i++){
        scanf("%d", &targets[i]);
    }
   
    vector<int> answers = getPossibleTargets(n, m, cards, targets);
   
    if(answers.size() == 0) { // 가능한 당첨번호가 없다면 NO를 출력
        printf("NO");
    }
    else { // 가능한 당첨번호가 존재한다면 해당 목록을 출력
        for(int i = 0; i < answers.size(); i++) {
            if(i > 0) {
                printf(" ");
            }
        printf("%d", answers[i]);
        }
    }
   
    delete[] cards; // 동적 할당 해제(습관)
    delete[] targets; // 동적 할당 해제(습관)
   
    return 0;
}