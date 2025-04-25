/*
 * 문제: 백준 1018번 - 체스판 다시 칠하기
 * 링크: https://www.acmicpc.net/problem/1018
 * 분류: 브루트포스, 구현
 *
 * 문제 설명:
 * - N×M 크기의 보드에서 8×8 크기의 체스판을 골라, 다시 칠해야 하는 정사각형 개수의 최소값을 구하는 문제.
 * - 체스판은 'B'(검정)과 'W'(흰색)이 번갈아가며 칠해져 있어야 한다.
 *
 * 입력:
 * - 첫째 줄에 N, M (8 ≤ N, M ≤ 50)
 * - 둘째 줄부터 N개의 줄에 보드의 각 행 상태가 주어진다. (B 또는 W)
 *
 * 출력:
 * - 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.
 *
 * 접근 방법:
 * - 모든 8×8 부분 보드에 대해 두 가지(왼쪽 위가 'B' 또는 'W') 패턴과 비교하여 다시 칠해야 하는 칸 수를 센다.
 * - 그 중 최솟값을 출력한다.
 *
 * 시간복잡도: O((N-7)×(M-7)×64)
 * 공간복잡도: O(N×M)
 */

#include <iostream>
#include <algorithm>
using namespace std;

char board[50][51]; // 각 행의 끝에 널문자('\0') 포함

// (x, y)에서 시작하는 8x8 체스판을 다시 칠해야 하는 최소 칸 수 반환
int repaint(int x, int y) {
    int cnt1 = 0; // 'W'로 시작
    int cnt2 = 0; // 'B'로 시작
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // (i+j)가 짝수면 시작 색, 홀수면 반대 색이어야 함
            if ((i + j) % 2 == 0) {
                if (board[x + i][y + j] != 'W') cnt1++; // 'W'로 시작
                if (board[x + i][y + j] != 'B') cnt2++; // 'B'로 시작
            } else {
                if (board[x + i][y + j] != 'B') cnt1++;
                if (board[x + i][y + j] != 'W') cnt2++;
            }
        }
    }
    return min(cnt1, cnt2);
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    int result = 64; // 8x8 전체가 다 바뀌는 경우가 최대
    // 모든 8x8 영역에 대해 최소 칠해야 하는 칸 수 계산
    for (int i = 0; i <= N - 8; ++i) {
        for (int j = 0; j <= M - 8; ++j) {
            result = min(result, repaint(i, j));
        }
    }
    cout << result << '\n';
    return 0;
}
