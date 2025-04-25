/*
 * 문제: 백준 10814번 - 나이순 정렬
 * 링크: https://www.acmicpc.net/problem/10814
 * 분류: 정렬, 구현
 *
 * 문제 설명:
 * - 온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다.
 * - 회원들을 나이 오름차순으로 정렬하되, 나이가 같으면 먼저 가입한 사람이 앞에 오도록 정렬한다.
 *
 * 입력:
 * - 첫째 줄에 회원 수 N (1 ≤ N ≤ 100,000)
 * - 둘째 줄부터 N개의 줄에 각 회원의 나이(1~200)와 이름(길이 ≤ 100, 알파벳 소문자)이 공백으로 구분되어 주어진다.
 *   입력은 가입한 순서로 주어진다.
 *
 * 출력:
 * - 나이순, 가입순으로 정렬한 결과를 한 줄에 한 명씩 "나이 이름" 형태로 출력한다.
 *
 * 접근 방법:
 * - 각 회원의 나이, 이름, 가입 순서를 구조체에 저장한다.
 * - 나이 오름차순, 나이가 같으면 가입 순서 오름차순으로 정렬한다.
 *   (가입 순서는 입력된 순서의 인덱스를 활용)
 * - C++의 stable_sort()를 사용하면 나이가 같을 때 입력 순서가 자동으로 보장된다.
 *
 * 시간복잡도: O(N log N)
 * 공간복잡도: O(N)
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 회원 정보를 저장할 구조체
struct Member {
    int age;
    string name;
    int order; // 가입 순서(입력 순서)
};

// 정렬 기준: 나이 오름차순, 나이가 같으면 가입 순서 오름차순
bool compare(const Member& a, const Member& b) {
    if (a.age != b.age)
        return a.age < b.age;
    else
        return a.order < b.order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Member> members(N);

    // 입력: 나이, 이름, 가입 순서 저장
    for (int i = 0; i < N; ++i) {
        cin >> members[i].age >> members[i].name;
        members[i].order = i;
    }

    // 안정 정렬(stable_sort)로 나이순, 가입순 정렬
    stable_sort(members.begin(), members.end(), compare);

    // 결과 출력
    for (const auto& m : members) {
        cout << m.age << ' ' << m.name << '\n';
    }

    return 0;
}
