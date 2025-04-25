/*
 * 문제: 백준 11050번 - 이항 계수 1
 * 링크: https://www.acmicpc.net/problem/11050
 * 분류: 수학, 구현, 조합론
 * 
 * 문제 설명:
 * - 자연수 n과 정수 k가 주어졌을 때, 이항 계수 nCk를 구하는 문제.
 * - 이항 계수는 n개의 원소 중 k개를 순서 없이 고르는 경우의 수로, 공식은 n! / (k! * (n-k)!) 이다.
 * 
 * 입력:
 * - 첫째 줄에 정수 n, k가 주어진다. (1 ≤ n ≤ 10, 0 ≤ k ≤ n)
 * 
 * 출력:
 * - nCk의 값을 출력한다.
 * 
 * 접근 방법:
 * - 팩토리얼 함수를 직접 구현하여 n!, k!, (n-k)!를 각각 구한 뒤, 공식에 따라 계산한다.
 * - n, k가 작으므로 오버플로우 걱정 없이 int형으로 충분하다.
 * 
 * 시간복잡도: O(n)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

// 팩토리얼을 구하는 함수
int factorial(int t) {
    int result = 1;
    for (int i = t; i > 0; i--) {
        result *= i;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    // 이항 계수 공식 적용: nCk = n! / (k! * (n-k)!)
    int result = factorial(n) / (factorial(k) * factorial(n - k));
    cout << result << '\n';

    return 0;
}
