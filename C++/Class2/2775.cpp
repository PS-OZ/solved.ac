/*
 * 문제: 백준 2775번 - 부녀회장이 될테야
 * 링크: https://www.acmicpc.net/problem/2775
 * 분류: 다이나믹 프로그래밍, 수학
 * 
 * 문제 설명:
 * - 아파트에 거주하는 조건은 a층의 b호에 살려면 (a-1)층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와 살아야 한다.
 * - 0층 i호에는 i명이 산다.
 * - 주어진 T개의 테스트 케이스에 대해 k층 n호에 몇 명이 살고 있는지 출력한다.
 * 
 * 입력:
 * - 첫째 줄에 테스트 케이스 수 T가 주어진다.
 * - 각 테스트 케이스는 한 줄에 정수 k(1 ≤ k ≤ 14)와 n(1 ≤ n ≤ 14)이 주어진다.
 * 
 * 출력:
 * - 각 테스트 케이스에 대해 k층 n호의 거주자 수를 출력한다.
 * 
 * 접근 방법:
 * - 동적 프로그래밍을 사용하여 각 층과 호수에 따른 거주자 수를 미리 계산한다.
 * - 0층은 1호부터 14호까지 각각 1, 2, ..., 14명으로 초기화한다.
 * - dp[k][n] = dp[k-1][n] + dp[k][n-1] 점화식을 사용하여 각 층과 호수별 거주자 수를 계산한다.
 * 
 * 시간 복잡도:
 * - O(k_max * n_max + T), k_max = 14, n_max =14로 상수 시간 처리 가능.
 * 
 * 공간 복잡도:
 * - O(k_max * n_max)로 15x15 배열 사용.
 */

#include <iostream>
using namespace std;

int main() {
    int dp[15][15] = {0};  // 0층~14층, 1호~14호 저장

    // 0층 초기화: 0층 i호 = i명
    for (int n = 1; n <= 14; ++n) {
        dp[0][n] = n;
    }

    // DP 테이블 채우기 (1층~14층)
    for (int k = 1; k <= 14; ++k) {
        for (int n = 1; n <= 14; ++n) {
            dp[k][n] = dp[k-1][n] + dp[k][n-1];  // 핵심 점화식
        }
    }

    // 테스트 케이스 처리
    int T;
    cin >> T;
    while (T--) {
        int k, n;
        cin >> k >> n;
        cout << dp[k][n] << '\n';  // 미리 계산된 값 출력
    }

    return 0;
}
