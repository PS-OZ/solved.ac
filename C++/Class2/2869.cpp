/*
 * 문제: 백준 2869번 - 달팽이는 올라가고 싶다
 * 링크: https://www.acmicpc.net/problem/2869
 * 분류: 수학, 구현
 * 
 * 문제 설명:
 * - 높이가 V미터인 나무 막대를 달팽이가 낮에는 A미터 올라가고, 밤에는 B미터 미끄러진다.
 * - 단, 정상에 올라간 후에는 미끄러지지 않는다.
 * - 달팽이가 나무 막대를 모두 올라가려면 며칠이 걸리는지 구하는 문제.
 * 
 * 입력:
 * - 첫째 줄에 세 정수 A, B, V가 공백으로 구분되어 주어진다. (1 ≤ B < A ≤ V ≤ 1,000,000,000)
 * 
 * 출력:
 * - 첫째 줄에 달팽이가 나무 막대를 모두 올라가는데 걸리는 최소 일수를 출력한다.
 * 
 * 접근 방법:
 * - 반복문을 사용하면 시간 초과가 발생할 수 있으므로 수학적으로 계산해야 한다.
 * - 마지막 날 낮에 정상에 도달하면 미끄러지지 않으므로, (V-A) 만큼만 밤에 미끄러지는 과정을 반복하고, 마지막 날 낮에 A만큼 올라가서 정상에 도달한다.
 * - 즉, (V-A)를 하루에 올라가는 거리(A-B)로 나눈 몫이 정상 도달 전까지 걸리는 날 수이고, 마지막 날을 더해주면 된다.
 * - 나머지가 있으면 하루를 더 추가해야 한다.
 * 
 * 시간복잡도: O(1)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;

    // 정상 도달 전까지의 거리(V-A)와 하루에 실제로 올라가는 거리(A-B)
    int days = (V - A) / (A - B) + 1; // 기본 일수(나머지 없이 딱 맞아떨어질 때)
    if ((V - A) % (A - B) != 0) {
        days++; // 나머지가 있으면 하루 더 필요
    }

    cout << days << '\n';
    return 0;
}
