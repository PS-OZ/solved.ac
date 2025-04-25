/*
 * 문제: 백준 11866번 - 요세푸스 문제 0
 * 링크: https://www.acmicpc.net/problem/11866
 * 분류: 구현, 자료구조, 큐
 *
 * 문제 설명:
 * - 1번부터 N번까지 N명이 원을 이루어 앉아있다.
 * - 양의 정수 K가 주어지면, 순서대로 K번째 사람을 제거한다.
 * - 한 사람이 제거되면 남은 사람들로 원을 따라 이 과정을 반복한다.
 * - 모든 사람이 제거될 때까지 이 과정을 반복하며, 제거되는 순서를 출력한다.
 *
 * 입력:
 * - 첫째 줄에 N과 K가 빈 칸을 사이에 두고 주어진다. (1 ≤ K ≤ N ≤ 1,000)
 *
 * 출력:
 * - <제거되는 순서> 형태로 출력한다. (예: <3, 6, 2, 7, 5, 1, 4>)
 *
 * 접근 방법:
 * - 큐(queue)에 1부터 N까지의 숫자를 넣는다.
 * - K-1번 큐의 앞 원소를 뒤로 보내고, K번째 원소를 제거(출력)한다.
 * - 큐가 빌 때까지 반복한다.
 *
 * 시간복잡도: O(NK)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    cout << "<";
    while (!q.empty()) {
        // K-1번 앞의 원소를 뒤로 보냄
        for (int i = 1; i < K; ++i) {
            q.push(q.front());
            q.pop();
        }
        // K번째 원소를 제거(출력)
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << ">\n";
    return 0;
}
