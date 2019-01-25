// 4. 후보키

#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

bool chk(vector<int> v, int value){
    int size = (int) v.size();
    
    for(int i=0; i<size; i++){
        if((v[i] & value) == v[i])
            return false;
    }
    return true;
}


int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = (int)relation.size();
    int col = (int)relation[0].size();
    
    vector<int> v;
    
    // i는 조합할 수 있는 총 경우의 수(2^col)
    for(int i=1; i<(1<<col); i++){
        map<string, int> m;
        // set<string> se;
        for(int j=0; j<row; j++) {
            string s = "";
            for(int k=0; k<col; k++) {
                if(i & (1<<k))
                    s += relation[j][k];
            }
            m[s]++;
            // se.insert(s);
        }
        
        // 현재 키가 최소성을 만족하는지 확인
        if(m.size() == row && chk(v,i)) { // map or set의 컨테이너 사이즈가 n인 것은 중복되는 값이 없다는 뜻
            v.push_back(i);
        }
    }
    
    answer = (int)v.size();
    return answer;
}