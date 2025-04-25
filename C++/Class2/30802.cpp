/*
 * 문제: 백준 30802번 - 웰컴 키트
 * 링크: https://www.acmicpc.net/problem/30802
 * 분류: 구현, 수학, 사칙연산
 * 
 * 문제 설명:
 * - 참가자 N명에게 티셔츠 1장, 펜 1자루씩 나눠준다.
 * - 티셔츠는 S, M, L, XL, XXL, XXXL 6가지 사이즈별로 신청자 수가 주어진다.
 * - 티셔츠는 같은 사이즈 T장씩 묶음 단위로만 주문할 수 있고, 부족하면 안 되며 남는 것은 괜찮다.
 * - 펜은 P자루씩 묶음 단위로 최대한 주문하고, 남는 것은 한 자루씩 주문해야 하며, 정확히 N자루 준비해야 한다.
 * 
 * 입력:
 * - 첫째 줄: 참가자 수 N (1 ≤ N ≤ 10^9)
 * - 둘째 줄: 각 티셔츠 사이즈별 신청자 수 S, M, L, XL, XXL, XXXL (합은 N)
 * - 셋째 줄: 티셔츠 묶음 단위 T, 펜 묶음 단위 P (2 ≤ T, P ≤ 10^9)
 * 
 * 출력:
 * - 첫째 줄: 티셔츠를 T장씩 최소 몇 묶음 주문해야 하는지
 * - 둘째 줄: 펜을 P자루씩 최대 몇 묶음 주문할 수 있는지와, 그 때 펜을 한 자루씩 몇 개 주문하는지
 * 
 * 접근 방법:
 * - 티셔츠: 각 사이즈별로 (신청자 수 / T) + (나머지가 있으면 1) 묶음을 주문, 모든 사이즈 합산
 * - 펜: N / P (묶음 주문), N % P (한 자루씩 주문)
 * 
 * 시간복잡도: O(1) (항상 6사이즈, 연산만)
 * 공간복잡도: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    long long N, T, P;
    long long size[6];
    cin >> N;
    for (int i = 0; i < 6; i++) cin >> size[i];
    cin >> T >> P;

    // 티셔츠 묶음 계산
    long long tshirtBundles = 0;
    for (int i = 0; i < 6; i++) {
        tshirtBundles += size[i] / T;
        if (size[i] % T != 0) tshirtBundles += 1;
    }
    cout << tshirtBundles << '\n';

    // 펜 묶음, 낱개 계산
    cout << N / P << " " << N % P << '\n';

    return 0;
}
