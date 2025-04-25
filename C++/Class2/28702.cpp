/*
 * 문제: 백준 28702번 - 수 이어 쓰기 3
 * 링크: https://www.acmicpc.net/problem/28702
 * 분류: 구현, 수학, 문자열
 * 
 * 문제 설명:
 * - 첫째 줄에 어떤 수 N이 주어진다.
 * - 둘째 줄부터 N의 뒤에 이어서 쓸 수 있는 수가 0~2개 주어진다.
 *   (이어서 쓸 수 있다는 것은, N의 마지막 한 자리 또는 두 자리가 그 수와 같다는 뜻)
 * - N의 뒤에 이어 쓸 수 있는 수가 1개면 N+1, 2개면 N+2, 0개면 N을 출력한다.
 * 
 * 입력:
 * - 첫째 줄에 N(1 ≤ N ≤ 10^18)이 주어진다.
 * - 둘째 줄부터 N의 뒤에 이어 쓸 수 있는 수가 0~2개 주어진다. (각 수는 1~99)
 * 
 * 출력:
 * - 이어 쓸 수 있는 수가 2개면 N+2, 1개면 N+1, 0개면 N을 출력한다.
 * 
 * 접근 방법:
 * - 입력으로 주어진 N과 이어 쓸 수 있는 수의 개수를 파악한다.
 * - 이어 쓸 수 있는 수가 몇 개인지 세어서 조건에 따라 N, N+1, N+2를 출력한다.
 * 
 * 시간복잡도: O(1)
 * 공간복잡도: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string N;
    getline(cin, N); // 첫 줄 N (최대 10^18, string으로 받음)
    int cnt = 0;
    string line;
    // 둘째 줄부터 최대 2줄까지 이어 쓸 수 있는 수가 주어짐
    while (getline(cin, line)) {
        if (!line.empty()) cnt++;
    }

    // 이어 쓸 수 있는 수의 개수에 따라 출력
    if (cnt == 2) {
        // N+2 출력
        // N이 매우 클 수 있으므로 string -> long long 변환 필요
        long long num = stoll(N);
        cout << num + 2 << '\n';
    } else if (cnt == 1) {
        long long num = stoll(N);
        cout << num + 1 << '\n';
    } else {
        cout << N << '\n';
    }
    return 0;
}
