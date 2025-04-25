/*
 * 문제: 백준 10816번 - 숫자 카드 2
 * 링크: https://www.acmicpc.net/problem/10816
 * 분류: 자료구조, 해시, 정렬, 이분 탐색
 *
 * 문제 설명:
 * - 상근이가 숫자 카드 N개를 가지고 있다.
 * - 정수 M개가 주어질 때, 각 수가 상근이의 숫자 카드에 몇 개 있는지 구해라.
 *
 * 입력:
 * - 첫째 줄: N (1 ≤ N ≤ 500,000)
 * - 둘째 줄: N개의 정수 (각각 -10,000,000 이상 10,000,000 이하)
 * - 셋째 줄: M (1 ≤ M ≤ 500,000)
 * - 넷째 줄: M개의 정수 (각각 -10,000,000 이상 10,000,000 이하)
 *
 * 출력:
 * - 각 쿼리마다 해당 수가 상근이의 숫자 카드에 몇 개 있는지 공백으로 구분해 출력
 *
 * 접근 방법:
 * - 해시맵(또는 C++의 unordered_map)을 이용해 각 숫자의 개수를 센다.
 * - 쿼리마다 해당 숫자의 개수를 출력한다.
 * - 시간복잡도: O(N + M)
 * - 공간복잡도: O(N)
 */

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, num;
    unordered_map<int, int> card_count;

    // 상근이의 숫자 카드 입력 및 개수 세기
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        card_count[num]++;
    }

    // 쿼리 처리 및 출력
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> num;
        cout << card_count[num] << ' ';
    }
    cout << '\n';
    return 0;
}
