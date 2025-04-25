/*
 * 문제: 백준 11650번 - 좌표 정렬하기
 * 링크: https://www.acmicpc.net/problem/11650
 * 분류: 정렬, 구현
 *
 * 문제 설명:
 * - 2차원 평면 위의 점 N개가 주어진다.
 * - 각 점을 x좌표 오름차순으로 정렬하되, x좌표가 같으면 y좌표 오름차순으로 정렬한다.
 *
 * 입력:
 * - 첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)
 * - 둘째 줄부터 N개의 줄에 각 점의 좌표 xi, yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000)
 *
 * 출력:
 * - 정렬된 좌표를 한 줄에 하나씩 "x y" 형태로 출력한다.
 *
 * 접근 방법:
 * - 각 좌표를 (x, y) 쌍으로 배열에 저장한다.
 * - C++의 sort() 함수와 사용자 정의 비교 함수를 사용해 x, y 기준으로 정렬한다.
 * - 입력이 많으므로 입출력 속도 향상을 위해 ios::sync_with_stdio(false), cin.tie(NULL)을 사용한다.
 *
 * 시간복잡도: O(N log N)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <algorithm>
using namespace std;

// 좌표를 저장할 구조체
struct Point {
    int x, y;
};

// 정렬 기준: x 오름차순, x가 같으면 y 오름차순
bool compare(const Point& a, const Point& b) {
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    Point* arr = new Point[N];

    // 좌표 입력
    for (int i = 0; i < N; ++i) {
        cin >> arr[i].x >> arr[i].y;
    }

    // 정렬
    sort(arr, arr + N, compare);

    // 출력
    for (int i = 0; i < N; ++i) {
        cout << arr[i].x << ' ' << arr[i].y << '\n';
    }

    delete[] arr;
    return 0;
}
