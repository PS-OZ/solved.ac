/*
 * 문제: 백준 15829번 - Hashing
 * 링크: https://www.acmicpc.net/problem/15829
 * 분류: 구현, 문자열, 해싱
 * 
 * 문제 설명:
 * - 소문자 알파벳으로 이루어진 문자열이 주어진다.
 * - 각 문자를 a=1, b=2, ..., z=26으로 변환한다.
 * - i번째(0-based) 문자는 (변환값) × 31^i로 변환한다.
 * - 모든 값을 더한 후 1234567891로 나눈 나머지를 출력한다.
 * 
 * 입력:
 * - 첫째 줄: 문자열의 길이 L (1 ≤ L ≤ 50)
 * - 둘째 줄: 길이 L의 소문자 문자열
 * 
 * 출력:
 * - 해시 값을 1234567891로 나눈 나머지
 * 
 * 접근 방법:
 * - 각 문자를 숫자로 변환하고, 31의 거듭제곱 값을 곱해 누적한다.
 * - 매 연산마다 1234567891로 나눈 나머지를 구해 overflow를 방지한다.
 * 
 * 시간복잡도: O(L)
 * 공간복잡도: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    const int M = 1234567891;
    const int r = 31;
    int L;
    string s;
    cin >> L >> s;

    long long hash = 0;
    long long pow_r = 1; // r^i 값을 저장

    for (int i = 0; i < L; i++) {
        int val = s[i] - 'a' + 1; // a=1, b=2, ..., z=26
        hash = (hash + val * pow_r) % M;
        pow_r = (pow_r * r) % M;
    }

    cout << hash;
    return 0;
}
