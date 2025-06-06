/*
 * 문제: 백준 3052번 - 나머지
 * 링크: https://www.acmicpc.net/problem/3052
 * 분류: 수학, 배열, 구현
 *  
 * 문제 설명:
 * - 10개의 수를 입력받아 각 수를 42로 나눈 나머지를 구한다.
 * - 42로 나누었을 때, 서로 다른 나머지가 몇 개 있는지 출력한다.
 * 
 * 입력:
 * - 첫째 줄부터 열 번째 줄까지 한 줄에 하나씩 자연수(0 이상 1,000 이하)가 주어진다.
 * 
 * 출력:
 * - 42로 나누었을 때, 서로 다른 나머지의 개수를 출력한다.
 * 
 * 접근 방법:
 * - 42칸짜리 배열(혹은 bool 배열)을 만들어, 각 수를 42로 나눈 나머지에 해당하는 인덱스를 true로 표시한다.
 * - 마지막에 true로 표시된 인덱스의 개수를 세어 출력한다.
 * 
 * 시간복잡도: O(1) (항상 10개의 입력, 42개의 배열 확인)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    bool remainder[42] = { false }; // 나머지 여부를 저장하는 배열
    int x, count = 0;

    for (int i = 0; i < 10; i++) {
        cin >> x; // 입력된 숫자
        remainder[x % 42] = true; // 나머지에 해당하는 인덱스를 true로 설정
    }

    for (int i = 0; i < 42; i++) {
        if (remainder[i]) { // 나머지가 존재하면 카운트 증가
            count++;
        }
    }

    cout << count; // 서로 다른 나머지의 개수 출력
    return 0;
}
