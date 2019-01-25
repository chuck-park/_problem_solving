#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    char a[50], b[50], c[50];
    map<string, string> mp;

    // Enter와 Change 마다 유저 아이디와 닉네임을 map으로 매핑 시켜줌
    for(int i=0; i<record.size(); i++) {
        sscanf(record[i].c_str(), "%s", a); // 문자열을 순차적으로 받아서 a에 넣는다

        if(a[0] == 'E') {
            sscanf(record[i].c_str(), "%s%s%s", a, b, c);
            mp[b] = c;
        }
        if(a[0] == 'C') {
            sscanf(record[i].c_str(), "%s%s%s", a, b, c);
            mp[b] = c;
        }
    }

    char output[50];
    for(int i=0; i<record.size(); i++) {
        sscanf(record[i].c_str(), "%s", a);

        if(a[0] == 'E') {
            sscanf(record[i].c_str(), "%s%s%s", a, b, c);
            sprintf(output, "%s님이 들어왔습니다.", mp[b].c_str());
            answer.push_back(output);
        }
        if(a[0] == 'L') {
            sscanf(record[i].c_str(), "%s%s", a, b);
            sprintf(output, "%s님이 나갔습니다.", mp[b].c_str());
            answer.push_back(output);
        }

    }
    return answer;
}

// int main() {
//     vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
//     vector<string> answer = solution(record);
//     for(int i=0; i<answer.size(); i++) cout << answer[i] << "\n";
// }