#include<iostream>
#include<stack>
#include<map>
using namespace std;

int main() {
    string str;
    stack<char> stack;
    bool vps = true;

    cin >> str;

//    for(int i=0; i<str.length(); i++) {
////        cout << s[i] << "\n";
//        stack.push(str[i]);
//    }

    for(int i=0; i<str.length(); i++) {
        if(!vps) {
            break;
        }
        else {
            switch (str[i]) {
                default:
                    continue;
                case '(':
                    stack.push(str[i]);
                    break;
                case '[':
                    stack.push(str[i]);
                    break;
                case ')':
                    if(stack.top() != '(') {
                        vps = false;
                        break;
                    }
                    stack.pop();
                    break;
                case ']':
                    if(stack.top() != '[') {
                        vps = false;
                        break;
                    }
                    stack.pop();
                    break;
            }
        }
    }
    if(vps) {
        char last = ' ';
        for(int i=0; i<str.length(); i++) {
            if(i > 0) last = str[i-1];
            if(str[i] == '(') stack.push(str[i]);
            if(str[i] == '[') stack.push(str[i]);
            if(str[i] == ')') {
                if(last == '(') {
                    
                }
            }
        }
    }
    else {
        cout << 0 << "\n";
    }
//    for(int i=0; i<str.length(); i++) {
//        cout << stack.top() << "\n";
//        stack.pop();
//    }
}