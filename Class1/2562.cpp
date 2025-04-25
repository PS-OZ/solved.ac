/*
 * 문제: 백준 2562번 - 최댓값
 * 링크: https://www.acmicpc.net/problem/2562
 * 분류: 구현, 배열
 * 
 * 문제 설명:
 * - 9개의 서로 다른 자연수가 한 줄에 하나씩 입력된다.
 * - 이 중 최댓값을 찾고, 그 최댓값이 몇 번째 입력값인지를 출력한다.
 * 
 * 입력:
 * - 9줄에 걸쳐 한 줄에 하나씩 자연수(100 미만)가 주어진다.
 * 
 * 출력:
 * - 첫째 줄에 최댓값을 출력한다.
 * - 둘째 줄에 그 최댓값이 몇 번째 수인지를 출력한다.
 * 
 * 접근 방법:
 * - 9번 입력을 받으면서, 현재까지의 최댓값과 그 위치(인덱스)를 저장한다.
 * - 최댓값이 갱신될 때마다 위치도 함께 갱신한다.
 * - 입력은 0번째가 아닌 1번째부터 시작하므로, 위치는 인덱스 + 1로 출력한다.
 * 
 * 시간복잡도: O(1) (입력 크기가 고정)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int num, maxValue = 0, maxIndex = 0;
    for (int i = 0; i < 9; i++) {
        cin >> num;
        if (num > maxValue) {
            maxValue = num;      // 최댓값 갱신
            maxIndex = i + 1;    // 위치(1-based index) 갱신
        }
    }
    cout << maxValue << "\n" << maxIndex;
    return 0;
}
