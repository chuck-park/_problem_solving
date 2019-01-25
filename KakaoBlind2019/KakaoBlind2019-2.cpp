#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> unclears(N+2); // 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수
    vector<int> clears(N+2); // 스테이지에 도달한 플레이어 수의 누적
    vector<pair<double, int>> vec; // <실패율, 스테이지 번호>를 저장

    // 실패율의 분자(unclears) 구하기
    for(int i=0; i<stages.size(); i++) {
        unclears[stages[i]]++;
    }

    // 실패율의 분모(clears) 구하기
    clears[N+1] = unclears[N+1]; // 최종 스테이지를 클리어한 플레이어 수
    for(int i=N; i>0; i--) {
        // i번째 스테이지에 도달한 플레이어 수 = i번째 스테이지를 클리어하지 못한 플레이어 수 + 이후 스테이지들에 도달한 플레이어의 수
        clears[i] = unclears[i] + clears[i+1];
    }

    // 각 실패율(unclears / clears) 구하기
    for(int i=1; i<N; i++) {
        if(!clears[i])vec.push_back({0,i}); // 스테이지에 도달한 플레이어 수가 0이면 {0, i}를 push
        else vec.push_back({(double)unclears[i]/clears[i], i});
    }

    // 스테이지 번호를 실패율의 내림차순으로 정렬
    sort(vec.begin(), vec.end(),
         [](pair<double, int> &a, pair<double, int> &b) {
             if(a.first == b.first) return a.second < b.second; // 두 실패율이 같으면 번호가 더 작은 순으로 정렬
             return a.first > b.first; // 실패율이 더 큰 순으로 정렬
         }
    );

    for(int i=0; i<vec.size(); i++) {
        answer.push_back(vec[i].second);
    }
//    // print
//    for(int i=1; i<N+2; i++) {
//        cout << unclears[i] << " ";
//    }
//    cout << "\n";
//    for(int i=1; i<N+2; i++) {
//        cout << clears[i] << " ";
//    }
//    cout << "\n";
//    for(int i=0; i<N; i++) {
//        cout << vec[i].first << " " << vec[i].second << "\n";
//    }

    return answer;
}

// int main() {
//     int N = 5;
//     vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
//     vector<int> answer = solution(N, stages);
//     for(int i=0; i<answer.size(); i++) cout << answer[i] << "\n";
// }