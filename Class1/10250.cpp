/*
 * 문제: 백준 10250번 - ACM 호텔
 * 링크: https://www.acmicpc.net/problem/10250
 * 분류: 구현, 수학
 *  
 * 문제 설명:
 * - H층 W개의 방이 있는 호텔에서 N번째 손님에게 방을 배정한다.
 * - 방 번호는 YYXX 또는 YXX 형식(YY: 층수, XX: 호수)으로, 손님은 엘리베이터에서 가까운 방(즉, 층을 우선적으로 채움)에 배정된다.
 * 
 * 입력:
 * - 첫째 줄에 테스트 케이스 개수 T가 주어진다.
 * - 이어서 각 테스트 케이스마다 H(층 수), W(각 층의 방 수), N(몇 번째 손님)이 주어진다. (1 ≤ H, W ≤ 99, 1 ≤ N ≤ H×W)
 * 
 * 출력:
 * - 각 테스트 케이스마다 N번째 손님에게 배정될 방 번호를 출력한다.
 * 
 * 접근 방법:
 * - N번째 손님의 층수는 floor = N % H, 호수는 room = N / H + 1 이다.
 * - 단, N이 H의 배수라면 floor = H, room = N / H 로 조정해야 한다.
 * - 방 번호는 (층수 * 100 + 호수) 형식으로 출력한다. 호수는 항상 두 자리로 맞춰 출력한다.
 * 
 * 시간복잡도: O(T)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; // 테스트 케이스 개수 입력

    while (T--) {
        int H, W, N;
        cin >> H >> W >> N; // 층 수, 각 층의 방 수, N번째 손님

        int floor = N % H;
        int room = N / H + 1;

        if (floor == 0) {
            floor = H;
            room = N / H;
        }

        // 방 번호는 층수*100 + 호수 형식, 호수는 두 자리로 맞춰 출력
        cout << floor * 100 + room << '\n';
    }

    return 0;
}
