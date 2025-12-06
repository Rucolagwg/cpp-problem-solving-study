#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    // 각 후보 이름과 득표수를 저장하는 key-value Map
    map<string, int> frequencyMap;

    int maxFrequency = 0; // 가장 높은 득표수

    // 각 이름이 하나 추가될 때마다 현재까지의 최다 득표수를 갱신. 최다 득표 후보 리스트를 갱신해나감
    for (int i = 0; i < N; i++) {
        string st;
        cin >> st;
        frequencyMap[st]++;
        int k = frequencyMap[st];
        if (k > maxFrequency) {
            maxFrequency = k;
        }
    }

    // 최다 득표 후보 수를 출력
    cout << maxFrequency << endl;

    // 최다 득표를 한 동점 후보들 이름을 사전순으로 출력
    map<string, int>::iterator it;
    for (it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
        if (it->second == maxFrequency) {
            printf("%s ", it->first.c_str());
        }
    }
}