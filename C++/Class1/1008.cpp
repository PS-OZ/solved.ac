/*
 * 문제: 백준 1008번 - A/B
 * 링크: https://www.acmicpc.net/problem/1008
 * 분류: 구현, 사칙연산, 실수 연산
 * 
 * 문제 설명:
 * - 두 실수 A와 B를 입력받아 A를 B로 나눈 값을 출력하는 문제.
 * - 결과는 소수점 아래 9자리까지 출력해야 한다.
 * 
 * 입력:
 * - 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)
 * 
 * 출력:
 * - A/B의 값을 소수점 아래 9자리까지 출력한다.
 * 
 * 접근 방법:
 * - 표준 입력으로 두 실수를 입력받아, C++의 입출력 조작자를 사용해 소수점 아래 9자리까지 고정 소수점으로 출력한다.
 * 
 * 시간복잡도: O(1)
 * 공간복잡도: O(1)
 */

#include <iostream>
#include <iomanip> // setprecision, fixed 사용을 위한 헤더
using namespace std;

int main() {
    double a, b;
    cin >> a >> b; // 두 실수 입력 받기

    // 소수점 아래 9자리까지 고정 소수점 형식으로 출력 설정
    cout << fixed << setprecision(9);
    cout << a / b; // 두 수의 나눗셈 결과 출력

    return 0;
}
