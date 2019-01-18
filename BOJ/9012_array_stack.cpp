#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define MAX 51

class Stack {
public:
    int head;
    char a[MAX];

    Stack() { head = 0; }

    bool push(char x) {
        if(head > MAX) {
            cout << "stack overflow";
            return false;
        }
        else {
            a[++head] = x;
            return true;
        }
    }

    char top() {
        return a[head];
    }

    char pop() {
        if(head == 0) {
            cout << "stack underflow";
            return 0;
        }
        else {
            char x = a[head--];
            return x;
        }
    }

    bool isEmpty() {
        return head == 0;
    }

    void show() {
        for(int i=0; i<head+1; i++) {
            cout << a[i];
        }
    }
};

bool check(string str) {
    Stack stack;

    for(int j=0; j<int(str.length()); j++) {
        // '('인 경우 push
        if(str[j] == '(') {
            stack.push(str[j]);
        }
        if(str[j] == ')') {
            if(!stack.isEmpty()) // ')'이고 스택이 비어있지 않으면 pop
                stack.pop();
            else
                return false; // ')' 인데 스택이 비어있으면 false
        }
    }
    // loop가 끝나고 스택이 empty이면 VPS(Valid Parenthesis String)이므로 true
    // loop가 끝나도 '('가 남아있는 경우 false
    return stack.isEmpty();
}

int main() {
    int T;
    cin >> T;

    for(int i=0; i<T; i++) {
        string str;
        cin >> str;

        if(check(str)) cout << "YES" << "\n";
        else cout << "NO"<< "\n";
    }
}
