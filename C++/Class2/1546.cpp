/*
 * 문제: 백준 1546번 - 평균
 * 링크: https://www.acmicpc.net/problem/1546
 * 분류: 구현, 수학, 배열
 * 
 * 문제 설명:
 * - 세준이는 시험 본 과목의 점수 중 최댓값 M을 골라, 모든 점수를 (점수 / M * 100)으로 조작한다.
 * - 조작된 점수들의 새로운 평균을 구한다.
 * 
 * 입력:
 * - 첫째 줄: 과목의 개수 N (1 ≤ N ≤ 1000)
 * - 둘째 줄: 각 과목의 점수 (0 ≤ 점수 ≤ 100, 적어도 하나는 0보다 큼)
 * 
 * 출력:
 * - 조작된 점수들의 새로운 평균을 출력한다.
 * - 절대오차 또는 상대오차가 10^-2 이하이면 정답으로 인정된다.
 * 
 * 접근 방법:
 * - 점수 배열을 입력받고, 최댓값 M을 찾는다.
 * - 각 점수를 (점수 / M * 100)으로 변환해 합산한다.
 * - 합산 결과를 N으로 나눠 평균을 출력한다.
 * 
 * 시간복잡도: O(N)
 * 공간복잡도: O(N)
 */

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    double scores[1000];
    double maxScore = 0.0;

    // 점수 입력 및 최댓값 찾기
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
        if (scores[i] > maxScore) maxScore = scores[i];
    }

    // 조작된 점수의 합 계산
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += (scores[i] / maxScore) * 100.0;
    }

    // 새로운 평균 출력
    cout << sum / N;

    return 0;
}
