class MinStack {
private:
    struct Node{
        int val;
        int minVal;
        Node* next;

        Node(int val, int minVal, Node* next) : val(val), minVal(minVal), next(next) {}
    };

    Node* head;

public:
    MinStack() {
        head = nullptr;

    }
    
    void push(int val) {
        if(!head){
            head = new Node(val, val, nullptr);
        }
        else{
            int newMin = min(val, head->minVal);
            Node* newNode = new Node(val, newMin, head);
            head = newNode;
        }
        
    }
    
    void pop() {
        if(head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    int top() {
        if (head) return head->val;
        throw runtime_error("stack is empty");
    }
    
    int getMin() {
        if(head) return head->minVal;
        throw runtime_error("Stack is empty");
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