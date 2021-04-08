class LRUCache {
public:
    int LRUsize;
    int currentsize;
    struct Node {
        int val;
        int key;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    Node* newnode(int k,int v) {
        Node* q = new Node();
        q->val = v;
        q->key = k;
        q->next = NULL;
        q->prev = NULL;
        return q;
    }
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        LRUsize = capacity;
        currentsize = 0;
        head = NULL;
        tail = NULL;
        mp = {};
    }
    
    int get(int key) {
        if(mp[key]) {
            Node* temp = mp[key];
            if(temp != tail) {
                temp->next->prev = temp->prev;
                if(temp != head) 
                    temp->prev->next = temp->next;
                else
                    head = head->next;
                temp->prev = tail;
                temp->next = NULL;
                tail->next = temp;
                tail = temp;
            }
            return mp[key]->val;
        } else 
            return -1;
    }
    
    void put(int key, int value) {
        if(mp[key]) {
            mp[key]->val = value;
            get(key);
        } else {
            if(isFull()) {
                Node* temp = newnode(key,value);
                mp.erase(head->key);
                head = head->next;
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
                mp[temp->key] = temp;
                
            } else {
                Node* temp = newnode(key,value);
                if(head == NULL) {
                    head = temp;
                    tail = temp;
                    mp[temp->key] = temp;
                    currentsize++;
                } else {
                    tail->next = temp;
                    temp->prev = tail;
                    tail = temp;
                    mp[temp->key] = temp;
                    currentsize++;
                }
            }
        }
    }
    
    bool isFull() {
        return currentsize == LRUsize;
    }
};
​
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
