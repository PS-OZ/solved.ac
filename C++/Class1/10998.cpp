/*
 * 문제: 백준 10998번 - A×B
 * 링크: https://www.acmicpc.net/problem/10998
 * 분류: 구현, 사칙연산
 * 
 * 문제 설명:
 * - 두 정수 A와 B를 입력받아 A×B(곱셈) 결과를 출력하는 문제.
 * 
 * 입력:
 * - 첫째 줄에 A와 B가 공백으로 구분되어 주어진다. (0 < A, B < 10)
 * 
 * 출력:
 * - 첫째 줄에 A×B의 결과를 출력한다.
 * 
 * 접근 방법:
 * - 두 정수를 입력받아 곱셈 연산을 수행한 뒤 결과를 출력한다.
 * 
 * 시간복잡도: O(1)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;       // 두 정수 입력
    cout << A * B;       // 곱셈 결과 출력
    return 0;
}
