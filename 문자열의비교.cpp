#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_LENGTH = 100000; // 문자열 길이 제한

class MyString{ // 구조체 선언
private:
    char *characters; // 문자열과 길이가 정의됨
    int length;

public:
    MyString(const char *str){
        this->length = strnlen(str, MAX_LENGTH);
        this->characters = new char[this->length];

        for(int i = 0; i < this->length; i += 1){
            this->characters[i] = str[i];
        }
    }

    MyString(const string & original){
        this->length = original.length();
        this->characters = new char[this->length];

        for(int i = 0; i < this->length; i += 1){
            this->characters[i] = original[i];
        }
    }

    ~MyString(){
        delete[] characters;
    }


    // o: 비교할 문자열 (오른쪽 항)
    bool operator < (const MyString &o) const{
        int n = min(this->length, o.length);
        for(int i = 0; i < n; i++){ // for문을 돌면서 this와 o의 문자열을 비교
            if(this->characters[i] < o.characters[i]){ // this가 o보다 사전순으로 앞설 때, true 반환
                return true;
            }
            else if(this->characters[i] > o.characters[i]){
                return false;
            }
        }
        // algorithm algo의 경우 앞 4글자 모두 동일하다. 이 경우, 길이가 짧은 문자열이 사전순으로 앞선다.
        if(this->length < o.length){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator > (const MyString &o) const{
        int n = min(this->length, o.length);

        for(int i = 0; i < n; i ++){
            if(this->characters[i] > o.characters[i]){ // o가 this보다 사전순으로 앞설 때, true 반환
                return true;
            }
            else if(this->characters[i] < o.characters[i]){
                return false;
            }
        }
        if(this->length > o.length){
            return true;
        }
        else {
            return false;
        }
    }
    // return true: 두 문자열 같을 때
    bool operator == (const MyString &o) const{
        if(this->length != o.length){
            return false;
        }

        for(int i = 0; i < this->length; i++){
            if(this->characters[i] != o.characters[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s1, s2; // 입력 받을 두개의 문자열
    cin >> s1 >> s2; // 문자열 입력 (추출 연산자)

    MyString mys1(s1); // 구조체 선언
    MyString mys2(s2);

    if(mys1 < mys2){ // 첫 줄 입력된 문자열이 사전순으로 앞설 때
        printf("-1"); // cout << "-1" << endl(줄바꿈 오퍼레이터)); (삽입연산자)
    }
    else if(mys1 > mys2){ //두번째 줄 입력된 문자열이 사전순으로 앞설 때
        printf("1");
    }
    else{ // 두 문자열이 같을 때
        printf("0"); 
    }

    return 0;
}