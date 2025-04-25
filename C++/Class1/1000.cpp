/*
 * 문제: 백준 1000번 - A+B
 * 링크: https://www.acmicpc.net/problem/1000
 * 분류: 구현, 사칙연산
 * 
 * 문제 설명:
 * - 두 정수 A와 B를 입력받아 A+B를 출력하는 문제.
 * 
 * 입력:
 * - 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)
 * 
 * 출력:
 * - A+B의 값을 출력한다.
 * 
 * 접근 방법:
 * - 표준 입력으로 두 정수를 받아, 두 수의 합을 출력한다.
 * 
 * 시간복잡도: O(1)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;      // 두 정수 입력 받기
    cout << a + b;      // 두 수의 합 출력
    return 0;
}
