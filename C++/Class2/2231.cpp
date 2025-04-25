/*
 * 문제: 백준 2231번 - 분해합
 * 링크: https://www.acmicpc.net/problem/2231
 * 분류: 브루트포스, 구현
 * 
 * 문제 설명:
 * - 자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구하는 문제.
 * - 어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다.
 *   - 분해합: M + (M의 각 자리수의 합)
 *   - 예: 245의 분해합은 245 + 2 + 4 + 5 = 256 → 245는 256의 생성자
 * - 생성자가 없는 경우 0을 출력한다.
 * 
 * 입력:
 * - 첫째 줄에 자연수 N (1 ≤ N ≤ 1,000,000)
 * 
 * 출력:
 * - N의 가장 작은 생성자를 출력. 생성자가 없으면 0 출력.
 * 
 * 접근 방법:
 * - 1부터 N-1까지 모든 수를 생성자 후보로 삼아, 각 수의 분해합을 계산한다.
 * - 분해합이 N과 같으면 해당 수가 가장 작은 생성자이므로 출력 후 종료.
 * - 끝까지 찾지 못하면 0을 출력.
 * 
 * 시간복잡도: O(N * D) (N: 입력값, D: 자리수)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

// 특정 수의 분해합을 구하는 함수
int decomposition_sum(int num) {
    int sum = num;
    while (num > 0) {
        sum += num % 10; // 일의 자리 더하기
        num /= 10;       // 다음 자리로 이동
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    int result = 0;
    // 1부터 N-1까지 모든 수에 대해 분해합을 검사
    for (int i = 1; i < N; i++) {
        if (decomposition_sum(i) == N) {
            result = i;
            break; // 가장 작은 생성자를 찾으면 종료
        }
    }

    cout << result;
    return 0;
}
