/*
 * 문제: 백준 2751번 - 수 정렬하기 2
 * 링크: https://www.acmicpc.net/problem/2751
 * 분류: 정렬, 구현
 *
 * 문제 설명:
 * - N개의 정수가 주어질 때, 이를 오름차순으로 정렬하여 출력하는 문제.
 * - 입력 수의 개수 N은 최대 1,000,000개로 대용량 입력에 적합한 효율적인 정렬이 필요하다.
 *
 * 입력:
 * - 첫째 줄에 수의 개수 N (1 ≤ N ≤ 1,000,000)
 * - 둘째 줄부터 N개의 줄에 하나씩 정수가 주어진다.
 *
 * 출력:
 * - 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 *
 * 접근 방법:
 * - C++ 표준 라이브러리의 sort() 함수(퀵/힙/병합 정렬 기반, O(N log N))를 사용한다[1].
 * - 배열의 크기가 크므로 전역 배열로 선언하거나, 벡터를 사용할 수 있다.
 * - 입출력 속도 향상을 위해 ios::sync_with_stdio(false), cin.tie(0) 사용을 권장한다.
 *
 * 시간복잡도: O(N log N)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <algorithm>
using namespace std;

int num[1000000]; // 최대 1,000,000개, 전역 배열로 선언

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(0);

    int N;
    cin >> N;

    // 입력 받기
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    // 정렬 (오름차순)
    sort(num, num + N);

    // 출력
    for (int i = 0; i < N; i++) {
        cout << num[i] << '\n';
    }

    return 0;
}
