/*
 * 문제: 백준 7568번 - 덩치
 * 링크: https://www.acmicpc.net/problem/7568
 * 분류: 브루트포스, 구현
 *
 * 문제 설명:
 * - N명의 사람에 대해 각자의 몸무게와 키가 주어진다.
 * - 두 사람 A(x, y), B(p, q)에 대해 x > p && y > q이면 A의 덩치가 B보다 크다.
 * - 자신의 덩치보다 더 큰 사람이 k명이라면, 자신의 등수는 k+1이 된다.
 *
 * 입력:
 * - 첫째 줄에 사람의 수 N (2 ≤ N ≤ 50)
 * - 둘째 줄부터 N개의 줄에 각 사람의 몸무게와 키가 주어진다.
 *
 * 출력:
 * - 각 사람의 덩치 등수를 공백으로 구분해 한 줄에 출력한다.
 *
 * 접근 방법:
 * - 모든 사람을 이중 반복문으로 비교하며, 자신보다 덩치가 큰 사람이 있을 때마다 등수를 1씩 증가시킨다.
 * - 완전탐색(브루트포스)로 충분히 해결 가능하다.
 *
 * 시간복잡도: O(N^2)
 * 공간복잡도: O(N)
 */

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int weight[50], height[50];

    // 각 사람의 몸무게와 키 입력
    for (int i = 0; i < N; ++i) {
        cin >> weight[i] >> height[i];
    }

    for (int i = 0; i < N; ++i) {
        int rank = 1; // 등수는 1부터 시작
        for (int j = 0; j < N; ++j) {
            if (i == j) continue; // 자기 자신과는 비교하지 않음
            // 다른 사람이 자신보다 몸무게, 키 모두 크면 등수 증가
            if (weight[j] > weight[i] && height[j] > height[i]) {
                rank++;
            }
        }
        cout << rank << ' ';
    }
    cout << '\n';
    return 0;
}
