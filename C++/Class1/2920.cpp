/*
 * 문제: 백준 2920번 - 음계
 * 링크: https://www.acmicpc.net/problem/2920
 * 분류: 구현, 배열
 * 
 * 문제 설명:
 * - 8개의 숫자가 주어진다. 1부터 8까지 오름차순이면 "ascending", 8부터 1까지 내림차순이면 "descending", 그 외에는 "mixed"를 출력한다.
 * 
 * 입력:
 * - 첫째 줄에 8개의 정수가 공백으로 구분되어 주어진다. (각 정수는 1 이상 8 이하, 중복 없음)
 * 
 * 출력:
 * - "ascending", "descending", "mixed" 중 하나를 출력한다.
 * 
 * 접근 방법:
 * - 입력받은 배열이 오름차순인지, 내림차순인지, 둘 다 아닌지 확인한다.
 * - 두 개의 불리언 변수를 사용하여 한 번의 반복문으로 판별한다.
 * 
 * 시간복잡도: O(1) (항상 8개의 입력)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[8];
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    bool isAscending = true;
    bool isDescending = true;

    for (int i = 0; i < 7; i++) {
        if (arr[i] < arr[i + 1]) {
            isDescending = false; // 내림차순이 아님
        } else if (arr[i] > arr[i + 1]) {
            isAscending = false; // 오름차순이 아님
        }
    }

    if (isAscending) {
        cout << "ascending";
    } else if (isDescending) {
        cout << "descending";
    } else {
        cout << "mixed";
    }

    return 0;
}
