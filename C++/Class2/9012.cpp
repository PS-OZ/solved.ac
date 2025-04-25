/*
 * 문제: 백준 9012번 - 괄호
 * 링크: https://www.acmicpc.net/problem/9012
 * 분류: 문자열, 스택, 구현
 *
 * 문제 설명:
 * - 여러 개의 괄호 문자열(PS: Parenthesis String)이 주어진다.
 * - 각 문자열이 올바른 괄호 문자열(VPS: Valid Parenthesis String)인지 판별한다.
 *   (짝이 맞고, 열고 닫는 순서가 올바르면 VPS)
 *
 * 입력:
 * - 첫째 줄에 테스트 케이스의 개수 T (1 ≤ T ≤ 50)
 * - 둘째 줄부터 T개의 줄에 괄호 문자열이 주어진다. (길이 ≤ 50)
 *
 * 출력:
 * - 각 문자열이 VPS면 "YES", 아니면 "NO"를 한 줄에 하나씩 출력한다.
 *
 * 접근 방법:
 * - 스택을 사용하여 '('는 push, ')'는 pop.
 * - pop할 때 스택이 비어 있으면 NO.
 * - 모든 문자 처리 후 스택이 비어 있으면 YES, 아니면 NO.
 *
 * 시간복잡도: O(L) (L: 문자열 길이)
 * 공간복잡도: O(L)
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        stack<char> st;
        bool isVPS = true;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    isVPS = false;
                    break;
                }
            }
        }
        // 문자열 처리 후 스택이 비어있어야 VPS
        if (isVPS && st.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
