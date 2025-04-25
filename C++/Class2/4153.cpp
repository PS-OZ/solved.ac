/*
 * 문제: 백준 4153번 - 직각삼각형
 * 링크: https://www.acmicpc.net/problem/4153
 * 분류: 수학, 기하학, 구현
 * 
 * 문제 설명:
 * - 세 변의 길이가 주어졌을 때, 직각삼각형인지 판별하는 문제.
 * - 입력이 "0 0 0"일 때 종료한다.
 * 
 * 입력:
 * - 각 줄에 삼각형의 세 변의 길이(1 ≤ 변의 길이 ≤ 30,000)가 주어진다.
 * - 입력의 마지막 줄에는 0 0 0이 주어진다.
 * 
 * 출력:
 * - 각 입력에 대해 "right"(직각삼각형), "wrong"(직각삼각형이 아님)을 한 줄에 하나씩 출력한다.
 * 
 * 접근 방법:
 * - 세 변을 입력받아 가장 긴 변을 빗변으로 간주한다.
 * - 피타고라스의 정리: a^2 + b^2 = c^2를 만족하면 직각삼각형이다.
 * - 0 0 0이 입력되면 반복을 종료한다.
 * 
 * 시간복잡도: O(1) (입력 한 줄당)
 * 공간복잡도: O(1)
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        // 세 변을 오름차순 정렬하여 가장 큰 변이 빗변이 되도록 함
        int sides[3] = {a, b, c};
        sort(sides, sides + 3);

        if (sides[0]*sides[0] + sides[1]*sides[1] == sides[2]*sides[2]) {
            cout << "right\n";
        } else {
            cout << "wrong\n";
        }
    }
    return 0;
}
