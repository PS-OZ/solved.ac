/*
 * 문제: 백준 1181번 - 단어 정렬
 * 링크: https://www.acmicpc.net/problem/1181
 * 분류: 문자열, 정렬
 *
 * 문제 설명:
 * - 알파벳 소문자로 이루어진 N개의 단어가 주어진다.
 * - 조건에 따라 단어를 정렬하여 출력한다.
 *   1. 길이가 짧은 것부터
 *   2. 길이가 같으면 사전순으로
 *   3. 같은 단어는 한 번만 출력
 *
 * 입력:
 * - 첫째 줄에 단어의 개수 N (1 ≤ N ≤ 20,000)
 * - 둘째 줄부터 N개의 줄에 단어가 한 줄에 하나씩 주어진다. (길이 ≤ 50)
 *
 * 출력:
 * - 조건에 따라 정렬한 단어를 한 줄에 하나씩 출력한다.
 *
 * 접근 방법:
 * - 모든 단어를 입력받아 중복을 제거한다(set 또는 unique 사용).
 * - 길이순, 사전순으로 정렬한다(정렬 비교 함수 사용).
 * - 정렬된 결과를 출력한다.
 *
 * 시간복잡도: O(N log N)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 정렬 비교 함수: 길이 짧은 순, 길이 같으면 사전순
bool compare(const string &a, const string &b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    else
        return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<string> words(N);

    // 단어 입력 받기
    for (int i = 0; i < N; ++i)
        cin >> words[i];

    // 정렬: 길이순, 사전순
    sort(words.begin(), words.end(), compare);

    // 중복 제거 및 출력
    cout << words[0] << '\n';
    for (int i = 1; i < N; ++i) {
        if (words[i] != words[i - 1])
            cout << words[i] << '\n';
    }

    return 0;
}
