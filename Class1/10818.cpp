/*
 * 문제: 백준 10818번 - 최소, 최대
 * 링크: https://www.acmicpc.net/problem/10818
 * 분류: 구현, 배열
 * 
 * 문제 설명:
 * - 첫째 줄에 정수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
 * - 둘째 줄에는 N개의 정수가 공백으로 구분되어 주어진다. (각 정수는 -1,000,000 이상 1,000,000 이하)
 * - N개의 정수 중 최솟값과 최댓값을 차례대로 출력한다.
 * 
 * 입력:
 * - 첫째 줄: 정수의 개수 N
 * - 둘째 줄: N개의 정수
 * 
 * 출력:
 * - 첫째 줄에 최솟값과 최댓값을 공백으로 구분해 출력한다.
 * 
 * 접근 방법:
 * - 첫 번째 입력값을 최솟값(min), 최댓값(max)으로 초기화한다.
 * - 나머지 값을 입력받으면서, 각 값이 min보다 작으면 min을 갱신, max보다 크면 max를 갱신한다.
 * - 모든 입력을 처리한 뒤 min과 max를 출력한다.
 * 
 * 시간복잡도: O(N)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N; // 정수의 개수 입력

    int num, minVal = 1000000, maxVal = -1000000; // 문제의 입력 범위에 맞게 초기화

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num < minVal) minVal = num; // 최솟값 갱신
        if (num > maxVal) maxVal = num; // 최댓값 갱신
    }

    cout << minVal << " " << maxVal;
    return 0;
}
