/*
 * 문제: 백준 4949번 - 균형잡힌 세상
 * 링크: https://www.acmicpc.net/problem/4949
 * 분류: 문자열, 자료구조(스택), 구현
 *
 * 문제 설명:
 * - 입력되는 각 문자열에서 소괄호 '()', 대괄호 '[]'가 올바르게 짝을 이루는지 판별한다.
 * - 올바른 짝: 여는 괄호는 반드시 같은 종류의 닫는 괄호와 1:1로 매칭되어야 하며, 괄호 사이의 모든 부분 문자열도 균형을 이뤄야 한다.
 * - 입력의 마지막 줄은 점 하나('.')로 이루어져 있으며, 이 줄이 입력되면 프로그램을 종료한다.
 *
 * 입력:
 * - 여러 줄의 문자열이 주어진다. (각 줄의 길이 ≤ 100)
 * - 마지막 줄은 "." 한 글자
 *
 * 출력:
 * - 각 줄마다 균형잡힌 문자열이면 "yes", 아니면 "no"를 출력한다.
 *
 * 접근 방법:
 * - 스택(Stack)을 사용해 여는 괄호는 push, 닫는 괄호는 스택의 top과 짝이 맞는지 확인 후 pop한다.
 * - 닫는 괄호가 나왔을 때 스택이 비었거나, 짝이 맞지 않으면 "no"를 출력한다.
 * - 모든 문자를 처리한 뒤 스택이 비어 있으면 "yes", 아니면 "no"를 출력한다.
 *
 * 시간복잡도: O(L) (L: 문자열의 길이)
 * 공간복잡도: O(L)
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    while (true) {
        string input;
        getline(cin, input); // 한 줄 입력

        if (input == ".") break; // 종료 조건

        stack<char> s;
        bool isBalanced = true;

        for (char c : input) {
            if (c == '(' || c == '[') {
                s.push(c); // 여는 괄호는 push
            } else if (c == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop(); // 짝이 맞으면 pop
                } else {
                    isBalanced = false; // 짝이 안 맞으면
                    break;
                }
            } else if (c == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop(); // 짝이 맞으면 pop
                } else {
                    isBalanced = false; // 짝이 안 맞으면
                    break;
                }
            }
            // 괄호 이외의 문자는 무시
        }

        // 모든 문자를 처리한 후 스택이 비어있어야 균형잡힘
        if (isBalanced && s.empty()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
