/*
 * 문제: 백준 11651번 - 좌표 정렬하기 2
 * 링크: https://www.acmicpc.net/problem/11651
 * 분류: 정렬, 구현
 *
 * 문제 설명:
 * - 2차원 평면 위의 점 N개가 주어진다.
 * - 각 점을 y좌표 오름차순으로 정렬하되, y좌표가 같으면 x좌표 오름차순으로 정렬한다.
 *
 * 입력:
 * - 첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)
 * - 둘째 줄부터 N개의 줄에 각 점의 좌표 xi, yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000)
 *
 * 출력:
 * - 정렬된 좌표를 한 줄에 하나씩 "x y" 형태로 출력한다.
 *
 * 접근 방법:
 * - 각 좌표를 pair<int, int>로 벡터에 저장한다.
 * - sort 함수와 사용자 정의 비교 함수를 사용해 y, x 기준으로 정렬한다.
 * - 입력이 많으므로 입출력 속도 향상을 위해 ios::sync_with_stdio(false), cin.tie(NULL)을 사용한다.
 *
 * 시간복잡도: O(N log N)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 정렬 기준: y 오름차순, y가 같으면 x 오름차순
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> points(N);

    // 좌표 입력
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // 정렬
    sort(points.begin(), points.end(), compare);

    // 출력
    for (int i = 0; i < N; ++i) {
        cout << points[i].first << ' ' << points[i].second << '\n';
    }

    return 0;
}
