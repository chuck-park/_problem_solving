/*
 * 가능한 속성조합 2^c-1개에 대해서 이 속성조합으로 만든 튜플들이 모두 독립 적이고,
 * 다른 속성조합의 부분집합이 아닌 경우를 세면 됩니다.
 *
 * 예를 들어 어떤 릴레이션의 어트리뷰트가 ABCDE 이고,
 * 슈퍼 키 집합이 {A, AB, BC, BCE, BDE, …} 라고 해봅시다.
 * 즉, A(0001)가 후보키라면 AB(0011)는 후보키가 될 수 없다는 뜻이 됩니다.
 * BC(0110)는 부분집합이 되는 다른 슈퍼키가 없으므로 후보키로 선택 됩니다.
 * BCE()
 *
 * 여기서 집합의 원리를 비트연산자를 이용해 구현할 수 있습니다.
 * i 번째 원소가 후보키 집합의 원소라면 1, 아니라면 0으로 비트를 설정한 숫자가 있을 때,
 * 최소성을 가지는 가지는 수는 다른 후보키와 AND 연산을 했을 때 자기 자신이 나오게 됩니다.
 *
 * 좀 더 자세히 설명하면, 1(0001) 과 3(0011) 이 있을 때, 1&3 = 1 이므로,
 * 1이 최종적인 후보키가 됨을 알 수 있습니다.
 *
 * i번째 튜플이 후보키 집합에 포함 되냐 되지 않느냐를 체크해야 하는데,
 * 튜플(컬럼)의 개수는 최대 8개이므로 최대 2^8 가지만 체크해보면 됩니다. 즉, 모든 경우의 수를 빠르게 체크할 수 있습니다.
 * 그러므로 i번째 원소가 포함 되는 경우, 안 되는 경우를 재귀함수로 구현하여 호출하면서,
 * 후보키 후보가 나왔을 때 비트 연산자를 통하여 최소성을 만족하면 정답이 됩니다.
 * 최종적으로 그런 후보키들을 저장하고 있는 배열의 크기를 반환합니다.
 *
 * http://xn--299as6vb5i1je.com/interview/98
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

/*
 * [[100,ryan,music,2],
 * [200,apeach,math,2],
 * [300,tube,computer,3],
 * [400,con,computer,4],
 * [500,muzi,music,3],
 * [600,apeach,music,2]]
 *         6 x 4
 */
bool check(vector<int> &vec, int now) {
    for(int i=0; i<vec.size(); i++) {
        if((vec[i]&now) == vec[i]) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    vector<int> answer;

    int r = (int)relation.size(); // 6
    int c = (int)relation[0].size(); // 4

    for(int i=1; i<(1<<c); i++) { // i<10000 == 1<2^4
        set<string> s;
        for(int j=0; j<r; j++) { // j<6, 2^4을 행의 개수(6) 만큼 만큼 반복
            string now="";
            for(int k=0; k<c; k++) { // k<4
                // 1~01111 & 1~10000
                //
                // 1&1, 1&10, 1&100, 1&1000
                // 10&1, 10&10, 10&100, 10&1000
                // 11&1, 11&10, 11&100, 11&1000
                // ...
                // 01111&1, 01111&10, 01111&100, 01111&1000
                if(i&(1<<k)) {
                    now += relation[j][k];

//                    cout << relation[j][k] << " ";
                }
            }
//            cout << "\n";

            s.insert(now);
//            cout << "now: " << now << "\n";
        }
        if(s.size() == r && check(answer, i)) answer.push_back(i);
    }

//    for(int i=0; i<relation.size(); i++) {
//        for (int j = 0; j < 4; j++)
//            cout << relation[i][j] << " ";
//        cout << "\n";
//    }

    return answer.size();
}

int main() {
    int N = 5;
    vector<vector<string>> relation({
        vector<string>({"100","ryan","music","2"}),
        vector<string>({"200","apeach","math","2"}),
        vector<string>({"300","tube","computer","3"}),
        vector<string>({"400","con","computer","4"}),
        vector<string>({"500","muzi","music","3"}),
        vector<string>({"600","apeach","music","2"})
    });

    int answer = solution(relation);
    cout << answer << "\n";
}