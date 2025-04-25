/*
 * 문제: 백준 2108번 - 통계학
 * 링크: https://www.acmicpc.net/problem/2108
 * 분류: 구현, 정렬, 수학
 *
 * 문제 설명:
 * - N개의 정수가 주어질 때, 다음 네 가지 통계값을 출력한다.
 *   1. 산술평균(반올림)
 *   2. 중앙값
 *   3. 최빈값(여러 개면 두 번째로 작은 값)
 *   4. 범위(최댓값 - 최솟값)
 *
 * 입력:
 * - 첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000, N은 홀수)
 * - 둘째 줄부터 N개의 줄에 정수(절댓값 ≤ 4,000)가 주어진다.
 *
 * 출력:
 * - 네 가지 통계값을 한 줄에 하나씩 출력한다.
 *
 * 접근 방법:
 * - 산술평균: 합을 N으로 나누고, 소수 첫째 자리에서 반올림
 * - 중앙값: 정렬 후 중앙 인덱스 값
 * - 최빈값: 카운팅 정렬(Counting Sort)로 빈도수 배열 생성, 여러 개면 두 번째로 작은 값 출력
 * - 범위: 정렬된 배열의 마지막 값 - 첫 값
 *
 * 시간복잡도: O(N log N) (정렬)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num, sum = 0;
    cin >> N;
    vector<int> v(N);
    int count[8001] = {0}; // -4000 ~ 4000

    for (int i = 0; i < N; ++i) {
        cin >> num;
        v[i] = num;
        sum += num;
        count[num + 4000]++;
    }

    sort(v.begin(), v.end());

    // 1. 산술평균 (반올림)
    cout << (int)round((double)sum / N) << '\n';

    // 2. 중앙값
    cout << v[N / 2] << '\n';

    // 3. 최빈값
    int max_freq = 0;
    for (int i = 0; i < 8001; ++i) {
        if (count[i] > max_freq)
            max_freq = count[i];
    }

    vector<int> modes;
    for (int i = 0; i < 8001; ++i) {
        if (count[i] == max_freq)
            modes.push_back(i - 4000);
    }
    // 여러 개면 두 번째로 작은 값
    if (modes.size() == 1)
        cout << modes[0] << '\n';
    else
        cout << modes[1] << '\n';

    // 4. 범위
    cout << v[N - 1] - v[0] << '\n';

    return 0;
}
