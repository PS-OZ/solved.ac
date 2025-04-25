/*
 * 문제: 백준 2609번 - 최대공약수와 최소공배수
 * 링크: https://www.acmicpc.net/problem/2609
 * 분류: 수학, 구현, 유클리드 호제법
 * 
 * 문제 설명:
 * - 두 개의 자연수를 입력받아 최대공약수(GCD)와 최소공배수(LCM)를 각각 출력하는 문제.
 * 
 * 입력:
 * - 첫째 줄에 두 개의 자연수(1 ≤ A, B ≤ 10,000)가 주어진다.
 * 
 * 출력:
 * - 첫째 줄에 최대공약수(GCD), 둘째 줄에 최소공배수(LCM)를 출력한다.
 * 
 * 접근 방법:
 * - 최대공약수(GCD)는 유클리드 호제법을 사용해 구한다.
 *   - GCD(a, b) = GCD(b, a % b), b가 0이 되면 a가 최대공약수.
 * - 최소공배수(LCM)는 두 수의 곱을 최대공약수로 나누어 구한다.
 *   - LCM(a, b) = (a * b) / GCD(a, b)
 * 
 * 시간복잡도: O(logN)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

// 유클리드 호제법을 이용한 최대공약수(GCD) 함수
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;

    int g = gcd(a, b);           // 최대공약수
    int l = (a * b) / g;         // 최소공배수

    cout << g << '\n' << l;
    return 0;
}
