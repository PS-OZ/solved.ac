/*
 * 문제: 백준 9498번 - 시험 성적
 * 링크: https://www.acmicpc.net/problem/9498
 * 분류: 구현, 조건문
 *  
 * 문제 설명:
 * - 시험 점수를 입력받아 점수 구간에 따라 등급(A, B, C, D, F)을 출력하는 문제.
 *   - 90 ~ 100점: A
 *   - 80 ~ 89점: B
 *   - 70 ~ 79점: C
 *   - 60 ~ 69점: D
 *   - 59점 이하: F
 * 
 * 입력:
 * - 첫째 줄에 시험 점수(0 이상 100 이하의 정수)가 주어진다.
 * 
 * 출력:
 * - 점수에 해당하는 등급을 한 줄에 출력한다.
 * 
 * 접근 방법:
 * - if ~ else if ~ else 조건문을 사용해 점수 구간에 따라 등급을 출력한다.
 * 
 * 시간복잡도: O(1)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score; // 시험 점수 입력

    if (score >= 90) {
        cout << "A";
    } else if (score >= 80) {
        cout << "B";
    } else if (score >= 70) {
        cout << "C";
    } else if (score >= 60) {
        cout << "D";
    } else {
        cout << "F";
    }

    return 0;
}
