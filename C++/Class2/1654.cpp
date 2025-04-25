/*
 * 문제: 백준 1654번 - 랜선 자르기
 * 링크: https://www.acmicpc.net/problem/1654
 * 분류: 이분 탐색, 매개변수 탐색
 * 
 * 문제 설명:
 * - 이미 가지고 있는 K개의 랜선을 잘라서 N개의 같은 길이의 랜선을 만들어야 한다.
 * - 만들 수 있는 최대 랜선 길이를 구하는 문제.
 *
 * 입력:
 * - 첫째 줄: K(1 ≤ K ≤ 10,000), N(1 ≤ N ≤ 1,000,000)
 * - 둘째 줄부터 K개의 줄: 각 랜선의 길이(1 ≤ 길이 ≤ 2^31-1)
 *
 * 출력:
 * - N개를 만들 수 있는 랜선의 최대 길이(정수)를 출력
 *
 * 접근 방법:
 * - 이분 탐색(이진 탐색)으로 가능한 최대 길이를 찾는다.
 *   1. 자를 길이(mid)를 정해 각 랜선에서 만들 수 있는 개수를 모두 합산한다.
 *   2. 합이 N 이상이면 길이를 늘리고, N 미만이면 줄인다.
 *   3. 이 과정을 반복해 최대 길이를 찾는다.
 *
 * 시간복잡도: O(K log L) (L: 최대 랜선 길이)
 * 공간복잡도: O(K)
 */

#include <iostream>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    long long arr[10000];
    long long max_len = 0;

    // 입력 및 최대 길이 찾기
    for (int i = 0; i < K; ++i) {
        cin >> arr[i];
        if (arr[i] > max_len) max_len = arr[i];
    }

    long long left = 1;
    long long right = max_len;
    long long answer = 0;

    // 이분 탐색으로 최대 길이 찾기
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        for (int i = 0; i < K; ++i) {
            cnt += arr[i] / mid;
        }
        if (cnt >= N) {
            answer = mid;      // 더 긴 길이도 시도
            left = mid + 1;
        } else {
            right = mid - 1;   // 더 짧게 잘라야 함
        }
    }

    cout << answer << '\n';
    return 0;
}
