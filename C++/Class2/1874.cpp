/*
 * 문제: 백준 1874번 - 스택 수열
 * 링크: https://www.acmicpc.net/problem/1874
 * 분류: 자료구조, 스택, 구현
 *
 * 문제 설명:
 * - 1부터 N까지의 수를 오름차순으로 스택에 push, pop 연산을 이용해 주어진 수열을 만들 수 있는지 판별한다.
 * - 만들 수 있다면 push 연산은 '+', pop 연산은 '-'로 출력하고, 만들 수 없다면 "NO"를 출력한다.
 *
 * 입력:
 * - 첫째 줄에 수열의 길이 N (1 ≤ N ≤ 100,000)
 * - 둘째 줄부터 N개의 줄에 수열의 각 수가 주어진다.
 *
 * 출력:
 * - push와 pop 연산을 한 줄에 하나씩 출력. 만들 수 없으면 "NO" 출력.
 *
 * 접근 방법:
 * - 1부터 N까지의 수를 오름차순으로 push.
 * - 스택의 top이 현재 수와 같으면 pop, 아니면 계속 push.
 * - 스택의 top과 수열의 수가 다르면 불가능("NO").
 *
 * 시간복잡도: O(N)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> sequence(N);
    for (int i = 0; i < N; ++i) {
        cin >> sequence[i];
    }

    stack<int> st;
    vector<char> result;
    int curr = 1; // 1부터 N까지 push할 숫자

    for (int i = 0; i < N; ++i) {
        int num = sequence[i];

        // num까지 push
        while (curr <= num) {
            st.push(curr);
            result.push_back('+');
            curr++;
        }

        // 스택의 top이 num이면 pop
        if (!st.empty() && st.top() == num) {
            st.pop();
            result.push_back('-');
        } else {
            // 불가능한 경우
            cout << "NO\n";
            return 0;
        }
    }

    // 결과 출력
    for (char c : result) {
        cout << c << '\n';
    }

    return 0;
}
