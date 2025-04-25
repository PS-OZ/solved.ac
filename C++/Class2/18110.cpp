/*
 * 문제: 백준 18110번 - solved.ac
 * 링크: https://www.acmicpc.net/problem/18110
 * 분류: 수학, 구현, 정렬
 *
 * 문제 설명:
 * - 난이도 의견 n개가 주어질 때, solved.ac가 계산하는 난이도를 출력한다.
 * - n이 0이면 난이도는 0이다.
 * - n이 1 이상이면, 30% 절사평균(위에서 15%, 아래에서 15%씩 반올림해서 제외)의 평균을 정수로 반올림해 출력한다.
 *
 * 입력:
 * - 첫째 줄에 난이도 의견의 개수 n (0 ≤ n ≤ 300,000)
 * - 둘째 줄부터 n개의 줄에 난이도 의견(1~30)이 주어진다.
 *
 * 출력:
 * - solved.ac가 계산한 난이도(정수)를 출력한다.
 *
 * 접근 방법:
 * - n이 0이면 0 출력.
 * - n이 1 이상이면, 입력을 정렬 후, 위/아래 15%씩 반올림해서 제외.
 * - 남은 값들의 평균을 구해 정수로 반올림해 출력한다.
 *
 * 시간복잡도: O(n log n)
 * 공간복잡도: O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // 위/아래에서 제외할 인원 수 (15% 반올림)
    int cut = (int)round(n * 0.15);

    int sum = 0;
    for (int i = cut; i < n - cut; ++i) {
        sum += v[i];
    }

    int cnt = n - 2 * cut;
    // 평균을 정수로 반올림
    int result = (int)round((double)sum / cnt);
    cout << result << '\n';

    return 0;
}
