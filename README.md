# C++ Problem Solving Study

C++로 알고리즘 문제를 풀며 정리한 저장소입니다.  
기초 문법과 입출력 연습부터 정렬, 탐색, 자료구조, 수학 문제까지 다양한 유형을 구현하며 문제 해결 능력을 쌓는 데 초점을 두었습니다.

This repository is a collection of algorithm and problem-solving practice written in C++.  
It focuses on building problem-solving skills by implementing a wide range of topics, from basic syntax and input/output practice to sorting, search, data structures, and mathematical problems.

## Repository Overview

각 `.cpp` 파일은 하나의 문제 또는 알고리즘 연습을 담고 있습니다.  
현재 저장소는 별도의 빌드 시스템 없이, 파일 단위로 컴파일하고 실행하는 방식으로 구성되어 있습니다.

Each `.cpp` file contains one problem solution or algorithm practice.  
There is no separate build system; each file is intended to be compiled and executed independently.

| Category / 구분 | Example Files / 예시 파일 | Description / 내용 |
| --- | --- | --- |
| Sorting / 정렬 | `버블정렬.cpp`, `선택정렬.cpp`, `오름차순인가.cpp` | Basic sorting algorithms and sorted-order checks |
| Search / 탐색 | `너비우선탐색.cpp`, `깊이우선탐색.cpp`, `탐색하기*.cpp` | BFS, DFS, graph/array search |
| Data Structures / 자료구조 | `괄호문자열.cpp`, `탑.cpp`, `히스토그램.cpp`, `중복제거하기.cpp` | Practice with stack, queue, set, and map |
| Math / 수학 | `소수세기.cpp`, `소수의판별.cpp`, `소인수분해.cpp`, `피보나치.cpp` | Prime numbers, factorization, and sequence calculations |
| Implementation / 구현 | `스도쿠보드.cpp`, `전화번호.cpp`, `두직사각형.cpp`, `픽셀수세기.cpp` | Condition handling and simulation-style problems |

## Topics

- C++ 기본 입출력과 조건문, 반복문
- 배열, 문자열, 구조체, 함수 분리
- `vector`, `queue`, `stack`, `set`, `map` 등 STL 활용
- 정렬 알고리즘 구현과 비교
- BFS/DFS 기반 그래프 탐색
- 소수 판별, 에라토스테네스의 체, 소인수분해
- 스택을 활용한 괄호 검사, 탑/히스토그램 문제 해결
- 문제 조건을 코드로 옮기는 구현 연습

English summary:

- Basic C++ input/output, conditionals, and loops
- Arrays, strings, structs, and function decomposition
- STL containers such as `vector`, `queue`, `stack`, `set`, and `map`
- Implementing and comparing sorting algorithms
- BFS/DFS-based graph traversal
- Prime checking, Sieve of Eratosthenes, and integer factorization
- Stack-based solutions for parentheses, tower, and histogram problems
- Translating problem statements and constraints into code

## How to Run

원하는 파일을 선택해 C++17 기준으로 컴파일합니다.

Choose a source file and compile it with C++17.

```bash
g++ -std=c++17 -O2 -Wall "파일이름.cpp" -o main
./main
```

예시:

```bash
g++ -std=c++17 -O2 -Wall "소수세기.cpp" -o prime_count
./prime_count
```

## Notes

이 저장소는 알고리즘과 자료구조를 공부하며 작성한 문제풀이 기록입니다.

This repository is a study log created while learning algorithms and data structures.  
