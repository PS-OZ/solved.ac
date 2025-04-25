/*
 * 문제: 백준 10845번 - 큐
 * 링크: https://www.acmicpc.net/problem/10845
 * 분류: 자료구조, 큐, 구현
 *
 * 문제 설명:
 * - 정수를 저장하는 큐를 구현하고, 입력으로 주어지는 명령을 처리하는 프로그램을 작성한다.
 * - 명령은 push X, pop, size, empty, front, back의 여섯 가지이다.
 *
 * 입력:
 * - 첫째 줄에 명령의 수 N (1 ≤ N ≤ 10,000)
 * - 둘째 줄부터 N개의 줄에 명령이 하나씩 주어진다.
 *
 * 출력:
 * - 출력해야 하는 명령이 주어질 때마다 한 줄에 하나씩 출력한다.
 *
 * 접근 방법:
 * - C++ STL의 queue를 사용하여 각 명령에 따라 조건문으로 처리한다.
 * - push는 큐에 값을 추가, pop은 맨 앞 값을 제거 및 출력, size/empty/front/back은 각각의 정보를 출력한다.
 * - 큐가 비어있을 때 pop, front, back 명령은 -1을 출력한다.
 *
 * 시간복잡도: O(N)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    queue<int> q;
    string cmd;

    for (int i = 0; i < N; ++i) {
        cin >> cmd;
        if (cmd == "push") {
            int x;
            cin >> x;
            q.push(x); // 정수 x를 큐에 추가
        } else if (cmd == "pop") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (cmd == "size") {
            cout << q.size() << '\n';
        } else if (cmd == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        } else if (cmd == "front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
            }
        } else if (cmd == "back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}
