/*
 * 문제: 백준 10773번 - 제로
 * 링크: https://www.acmicpc.net/problem/10773
 * 분류: 자료구조, 스택, 구현
 *
 * 문제 설명:
 * - K개의 수가 차례로 주어진다.
 * - 각 수를 차례대로 스택에 넣되, 0이 입력되면 가장 최근에 넣은 수를 스택에서 제거한다.
 * - 입력이 끝난 후, 스택에 남아있는 모든 수의 합을 출력한다.
 *
 * 입력:
 * - 첫째 줄에 정수 K (1 ≤ K ≤ 100,000)
 * - 둘째 줄부터 K개의 줄에 정수(0 ≤ 입력값 ≤ 1,000,000)가 한 줄에 하나씩 주어진다.
 *   (0이 입력될 때마다 스택에 값이 존재함이 보장된다)
 *
 * 출력:
 * - 스택에 남아 있는 수의 합을 출력한다.
 *
 * 접근 방법:
 * - 스택 자료구조를 사용하여 0이 아닌 수는 push, 0이 입력되면 pop을 수행한다.
 * - 마지막에 스택에 남은 모든 수를 합산하여 출력한다.
 *
 * 시간복잡도: O(K)
 * 공간복잡도: O(K)
 */

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int K;
    cin >> K;

    stack<int> s;
    for (int i = 0; i < K; ++i) {
        int num;
        cin >> num;
        if (num == 0 && !s.empty()) {
            s.pop(); // 0이 입력되면 최근 수 제거
        } else {
            s.push(num); // 0이 아니면 스택에 추가
        }
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum << '\n';
    return 0;
}
