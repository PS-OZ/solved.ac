/*
 * 문제: 백준 1259번 - 팰린드롬수
 * 링크: https://www.acmicpc.net/problem/1259
 * 분류: 문자열, 구현
 * 
 * 문제 설명:
 * - 주어진 수가 앞에서부터 읽어도, 뒤에서부터 읽어도 같은 수(팰린드롬수)인지 판별하는 문제.
 * - 입력은 여러 개의 테스트 케이스로 이루어져 있으며, 마지막 입력은 0이다(0은 판별하지 않음).
 * 
 * 입력:
 * - 각 줄마다 1 이상 99999 이하의 정수가 주어진다.
 * - 마지막 줄에는 0이 주어진다.
 * 
 * 출력:
 * - 각 수가 팰린드롬수면 "yes", 아니면 "no"를 한 줄에 하나씩 출력한다.
 * 
 * 접근 방법:
 * - 입력값을 문자열로 받아 양 끝에서부터 비교하며 팰린드롬 여부를 판별한다.
 * - 또는 reverse() 함수를 이용해 뒤집은 문자열과 비교해도 된다.
 * 
 * 시간복잡도: O(L) (L: 입력 수의 자릿수, 최대 5)
 * 공간복잡도: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    while (true) {
        cin >> num;
        if (num == "0") break;

        bool isPalindrome = true;
        int len = num.length();
        for (int i = 0; i < len / 2; i++) {
            if (num[i] != num[len - 1 - i]) {
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
