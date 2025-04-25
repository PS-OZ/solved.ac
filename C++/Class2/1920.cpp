/*
 * 문제: 백준 1920번 - 수 찾기
 * 링크: https://www.acmicpc.net/problem/1920
 * 분류: 이분 탐색, 정렬
 *
 * 문제 설명:
 * - N개의 정수로 이루어진 배열 A가 주어진다.
 * - M개의 수가 주어질 때, 각각의 수가 배열 A에 존재하는지 확인하여 존재하면 1, 아니면 0을 출력한다.
 *
 * 입력:
 * - 첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)
 * - 둘째 줄에 N개의 정수 A[1], ..., A[N] (정수 범위: -2,147,483,648 ~ 2,147,483,647)
 * - 셋째 줄에 M(1 ≤ M ≤ 100,000)
 * - 넷째 줄에 M개의 정수
 *
 * 출력:
 * - 각 수마다 배열 A에 존재하면 1, 아니면 0을 한 줄씩 출력
 *
 * 접근 방법:
 * - 배열 A를 오름차순 정렬한 뒤, 각 쿼리마다 이분 탐색을 수행하여 존재 여부를 확인한다.
 * - 시간복잡도: O(N log N + M log N)
 * - 공간복잡도: O(N)
 */

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000]; // N 최대 100,000

// 이분 탐색 함수: target이 arr[0..N-1]에 있으면 1, 없으면 0 반환
int binary_search(int arr[], int N, int target) {
    int left = 0, right = N - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return 1;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(arr, arr + N); // 이분 탐색 전 정렬

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        cout << binary_search(arr, N, num) << '\n';
    }
    return 0;
}
