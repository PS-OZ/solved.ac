/*
 * 문제: 백준 10828번 - 스택
 * 링크: https://www.acmicpc.net/problem/10828
 * 분류: 자료구조, 스택, 구현
 *
 * 문제 설명:
 * - 정수를 저장하는 스택을 구현하고, 입력으로 주어지는 명령을 처리하는 프로그램을 작성한다.
 * - 명령은 push X, pop, size, empty, top의 다섯 가지이다.
 *
 * 입력:
 * - 첫째 줄에 명령의 수 N (1 ≤ N ≤ 10,000)
 * - 둘째 줄부터 N개의 줄에 명령이 하나씩 주어진다.
 *
 * 출력:
 * - 출력해야 하는 명령이 주어질 때마다 한 줄에 하나씩 출력한다.
 *
 * 접근 방법:
 * - C++ STL의 stack을 사용하거나, 배열로 직접 구현할 수 있다.
 * - 각 명령에 따라 조건문으로 분기하여 처리한다.
 *
 * 시간복잡도: O(N)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num;
    cin >> N;
    stack<int> st;
    string cmd;

    for (int i = 0; i < N; ++i) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> num;
            st.push(num); // 정수 num을 스택에 추가
        } else if (cmd == "pop") {
            if (st.empty()) {
                cout << "-1\n"; // 스택이 비었으면 -1 출력
            } else {
                cout << st.top() << '\n'; // 가장 위의 값 출력
                st.pop(); // 그리고 제거
            }
        } else if (cmd == "size") {
            cout << st.size() << '\n'; // 스택에 들어있는 정수 개수 출력
        } else if (cmd == "empty") {
            cout << (st.empty() ? 1 : 0) << '\n'; // 비었으면 1, 아니면 0 출력
        } else if (cmd == "top") {
            if (st.empty()) {
                cout << "-1\n"; // 스택이 비었으면 -1 출력
            } else {
                cout << st.top() << '\n'; // 가장 위의 값 출력
            }
        }
    }
    return 0;
}
