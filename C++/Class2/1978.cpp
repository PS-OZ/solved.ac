/*
 * 문제: 백준 1978번 - 소수 찾기
 * 링크: https://www.acmicpc.net/problem/1978
 * 분류: 수학, 구현, 소수 판별
 * 
 * 문제 설명:
 * - 주어진 N개의 자연수 중에서 소수가 몇 개인지 찾아서 출력하는 문제.
 * - 소수란 1과 자기 자신만을 약수로 가지는 1보다 큰 자연수이다.
 * 
 * 입력:
 * - 첫째 줄에 수의 개수 N이 주어진다. (1 ≤ N ≤ 100)
 * - 둘째 줄에 N개의 자연수가 공백으로 구분되어 주어진다. (각 수는 1,000 이하)
 * 
 * 출력:
 * - 주어진 수들 중 소수의 개수를 출력한다.
 * 
 * 접근 방법:
 * - 각 수에 대해 2부터 √num까지 나눠서 나누어떨어지는 수가 있으면 소수가 아니다.
 * - 1은 소수가 아니므로 예외 처리한다.
 * 
 * 시간복잡도: O(N√M) (N: 수의 개수, M: 최대 자연수 1,000)
 * 공간복잡도: O(1)
 */

#include <iostream>
#include <cmath>
using namespace std;

// 소수 판별 함수
bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N, num, cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (is_prime(num)) cnt++;
    }
    cout << cnt;
    return 0;
}
