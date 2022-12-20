#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int value) {
        val = value;
        next = nullptr;
    }

    Node (int value, Node* next) {
        val = value;
        this->next = next;
    }

};

class MinStack {
private:
    Node* minList;
    vector<int> stack;
public:
    MinStack() {
        minList = nullptr;
    }
    
    void push(int val) {
        this->stack.push_back(val);
        if (minList == nullptr) {
            minList = new Node(val);
        } else {
            if (val <= minList->val) {
                minList = new Node(val, minList);
            }
        }
    }
    
    void pop() {
        int top = stack.back();
        stack.pop_back();

        if (top == this->minList->val) {
            Node* temp = minList;
            minList = minList->next;
            delete temp;
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return this->minList->val;
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
