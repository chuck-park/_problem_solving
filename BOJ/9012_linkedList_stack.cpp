#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class UnderflowException{};

template<typename T>
class Node {
public:
    T value;
    Node<T> *next;

    Node(T v, Node<T> *n): value(v), next(n){}
};

template<typename T>
class Stack {
public:
    int size;
    Node<T> *head;
    Stack(): size(0), head(nullptr){}

    void push(T value) {
        head = new Node<T>(value, head);
        size++;
    }

    T top() {
        try {
            if(size == 0) throw UnderflowException();

            return head->value;
        }
        catch(UnderflowException e) {
            cerr << "스택이 비어 있는데 top 연산을 시도했습니다." << endl;
            exit(1);
        }
    }

    void pop() {
        try {
            if(size == 0) throw UnderflowException();

            Node<T> *temp = head->next;
            delete head;
            head = temp;
            size--;
        }
        catch(UnderflowException e) {
            cerr << "스택이 비어 있는데 pop 연산을 시도했습니다." << endl;
            exit(2);
        }
    }

    bool isEmpty() {
        return size == 0;
    }
};

bool check(string str) {
    Stack<char> stack;

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
