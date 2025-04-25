/*
 * 문제: 백준 1966번 - 프린터 큐
 * 링크: https://www.acmicpc.net/problem/1966
 * 분류: 구현, 큐, 시뮬레이션
 *
 * 문제 설명:
 * - 문서의 중요도가 주어질 때, 특정 위치의 문서가 몇 번째로 인쇄되는지 구하는 문제.
 * - 중요도가 높은 문서가 있으면 현재 문서를 맨 뒤로 보낸다. 그렇지 않으면 인쇄한다.
 *
 * 입력:
 * - 첫째 줄: 테스트 케이스 개수 T
 * - 각 테스트 케이스
 *   - 첫째 줄: 문서의 개수 N, 궁금한 문서의 현재 위치 M
 *   - 둘째 줄: N개의 문서 중요도
 *
 * 출력:
 * - 각 테스트 케이스마다 궁금한 문서가 몇 번째로 인쇄되는지 출력
 *
 * 접근 방법:
 * - 큐에 (문서 인덱스, 중요도) 형태로 저장
 * - 현재 큐 내에서 가장 높은 중요도가 아니면 맨 뒤로 보냄
 * - 가장 높으면 인쇄(카운트 증가), 그 문서가 M이면 카운트 출력
 *
 * 시간복잡도: O(N^2) (N: 문서 개수)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, cnt = 0;
        cin >> N >> M;
        queue<pair<int, int>> q;
        int priority[10] = {0}; // 중요도별 문서 개수(1~9)

        // 입력: 문서의 중요도와 인덱스를 큐에 저장, 중요도별 개수 카운트
        for (int i = 0; i < N; ++i) {
            int p;
            cin >> p;
            q.push({i, p});
            priority[p]++;
        }

        while (!q.empty()) {
            int idx = q.front().first;
            int val = q.front().second;
            q.pop();

            // 현재 큐에 val보다 높은 중요도가 있는지 확인
            bool has_higher = false;
            for (int i = val + 1; i <= 9; ++i) {
                if (priority[i] > 0) {
                    has_higher = true;
                    break;
                }
            }

            if (has_higher) {
                q.push({idx, val}); // 뒤로 보냄
            } else {
                cnt++;
                priority[val]--; // 해당 중요도 문서 개수 감소
                if (idx == M) { // 찾는 문서라면
                    cout << cnt << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
