/*
 * 문제: 백준 1929번 - 소수 구하기
 * 링크: https://www.acmicpc.net/problem/1929
 * 분류: 수학, 소수 판정, 에라토스테네스의 체
 *
 * 문제 설명:
 * - 자연수 M과 N이 주어질 때, M 이상 N 이하의 모든 소수를 오름차순으로 출력한다.
 *
 * 입력:
 * - 첫째 줄에 자연수 M, N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)
 *
 * 출력:
 * - M 이상 N 이하의 소수를 한 줄에 하나씩 오름차순으로 출력한다.
 *
 * 접근 방법:
 * - 에라토스테네스의 체 알고리즘을 사용하여 N 이하의 모든 소수를 미리 판별한다.
 * - M부터 N까지의 수 중 소수인 것만 출력한다.
 * - 1은 소수가 아니므로 반드시 제외한다.
 *
 * 시간복잡도: O(N log log N)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<bool> is_prime(N + 1, true); // 0~N까지 소수 여부 저장
    is_prime[0] = is_prime[1] = false;  // 0과 1은 소수가 아님

    // 에라토스테네스의 체
    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // M부터 N까지 소수만 출력
    for (int i = M; i <= N; ++i) {
        if (is_prime[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}
