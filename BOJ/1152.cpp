#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int answer = 0;

    for(int i=0; i<str.length(); i++) {
        if(str.at(i) == ' ') answer++;
    }

    if(str.at(0) == ' ') answer--;

    if(str.at(str.length()-1) == ' ') answer--;

    cout << answer+1 << "\n";
}