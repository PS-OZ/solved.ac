/*
 * 문제: 백준 10871번 - X보다 작은 수
 * 링크: https://www.acmicpc.net/problem/10871
 * 분류: 구현, 반복문
 *  
 * 문제 설명:
 * - 정수 N개로 이루어진 수열 A와 정수 X가 주어진다.
 * - A에서 X보다 작은 수를 입력받은 순서대로 공백으로 구분해 출력한다.
 * 
 * 입력:
 * - 첫째 줄에 N과 X가 주어진다. (1 ≤ N, X ≤ 10,000)
 * - 둘째 줄에 수열 A를 이루는 정수 N개가 주어진다. (각 정수는 1 이상 10,000 이하)
 * 
 * 출력:
 * - X보다 작은 수를 입력받은 순서대로 공백으로 구분해 출력한다.
 * 
 * 접근 방법:
 * - N개의 수를 입력받으면서, 각 수가 X보다 작으면 바로 출력한다.
 * - 배열을 따로 사용하지 않고, 입력과 동시에 조건을 검사해 출력하는 것이 효율적이다.
 * 
 * 시간복잡도: O(N)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int N, X, val;
    cin >> N >> X; // 수열의 크기 N과 기준값 X 입력

    for (int i = 0; i < N; i++) {
        cin >> val;           // 수열의 각 원소 입력
        if (val < X) {
            cout << val << " "; // X보다 작으면 출력
        }
    }
    return 0;
}
