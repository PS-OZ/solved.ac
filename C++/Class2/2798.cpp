/*
 * 문제: 백준 2798번 - 블랙잭
 * 링크: https://www.acmicpc.net/problem/2798
 * 분류: 브루트포스, 구현
 * 
 * 문제 설명:
 * - N장의 카드 중 3장을 골라 합이 M을 넘지 않으면서 M에 최대한 가까운 값을 구하는 문제.
 * 
 * 입력:
 * - 첫째 줄: 카드의 개수 N(3 ≤ N ≤ 100), 목표값 M(10 ≤ M ≤ 300,000)
 * - 둘째 줄: 카드에 쓰여 있는 수 N개 (각각 100,000 이하의 양의 정수)
 * 
 * 출력:
 * - M을 넘지 않으면서 M과 최대한 가까운 카드 3장의 합을 출력한다.
 * 
 * 접근 방법:
 * - 모든 3장의 카드 조합을 브루트포스로 탐색한다.
 * - 각 조합의 합이 M 이하면, 현재까지의 최대값과 비교해 더 크면 갱신한다.
 * 
 * 시간복잡도: O(N^3) (N ≤ 100이므로 충분히 가능)
 * 공간복잡도: O(N)
 */

#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int cards[100];
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    int result = 0;
    // 세 장의 카드 조합을 모두 탐색
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = cards[i] + cards[j] + cards[k];
                if (sum <= M && sum > result) {
                    result = sum;
                }
            }
        }
    }
    cout << result;
    return 0;
}
