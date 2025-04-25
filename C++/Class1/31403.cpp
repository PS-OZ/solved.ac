/*
 * 문제: 백준 31403번 - A+B-C
 * 링크: https://www.acmicpc.net/problem/31403
 * 분류: 구현, 문자열, 사칙연산
 *  
 * 문제 설명:
 * - 정수 A, B, C가 입력된다.
 * - 첫 번째 줄에는 A, B, C를 모두 수로 생각했을 때 A+B-C의 결과를 출력한다.
 * - 두 번째 줄에는 A, B, C를 문자열로 생각해 A와 B를 이어붙인 후 정수로 변환하고, C를 정수로 변환해 빼서 출력한다.
 *   (즉, int(A+B) - int(C))
 * 
 * 입력:
 * - 첫째 줄: 정수 A (1 ≤ A ≤ 1,000)
 * - 둘째 줄: 정수 B (1 ≤ B ≤ 1,000)
 * - 셋째 줄: 정수 C (1 ≤ C ≤ 1,000)
 * - 모든 수는 0으로 시작하지 않는 양의 정수
 * 
 * 출력:
 * - 첫째 줄: (A+B)-C (A, B, C를 정수로 변환해 계산)
 * - 둘째 줄: (int(A+B))-int(C) (A, B를 문자열로 이어붙여 정수로 변환 후 C를 뺀 값)
 * 
 * 접근 방법:
 * - 입력을 문자열로 받아 각각 정수 변환 및 문자열 이어붙이기를 수행한다.
 * - 첫 번째 출력: stoi(A) + stoi(B) - stoi(C)
 * - 두 번째 출력: stoi(A + B) - stoi(C)
 * 
 * 시간복잡도: O(1)
 * 공간복잡도: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B >> C; // 세 수를 문자열로 입력받음

    // 첫째 줄: 정수로 계산
    cout << stoi(A) + stoi(B) - stoi(C) << '\n';

    // 둘째 줄: 문자열로 이어붙인 후 계산
    cout << stoi(A + B) - stoi(C);

    return 0;
}
