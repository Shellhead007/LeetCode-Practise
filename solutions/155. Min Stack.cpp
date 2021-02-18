class MinStack {
public:
    /** initialize your data structure here. */
     struct Node {
        int val;
        int min;
        Node* next;
    };
    Node* head;
    Node* newnode(int x,int min) {
        Node* new_node = new Node();
        new_node->val = x;
        new_node->min = min;
        new_node->next = NULL;
        return new_node;
    }
    
    Node* new_node1(int x,int min,Node* next) {
        Node* newnode1 = new Node();
        newnode1->val = x;
        newnode1->min = min;
        newnode1->next = next;
        return newnode1;
    }
    MinStack() {
        head = NULL;
    }
    
    void push(int x) {
        if(head == NULL)
            head = newnode(x,x);
        else
            head = new_node1(x,min(x,head->min),head);
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};
​
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
