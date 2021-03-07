class CustomStack {
public:
    int n;
    vector<int>arr;
    CustomStack(int maxSize) {
        n = maxSize;
        arr = std::vector<int>(0);
    }
    
    void push(int x) {
        if(arr.size() == n)
            return;
        arr.push_back(x);
    }
    
    int pop() {
        if(arr.size() == 0)
            return -1;
        int temp = arr[arr.size()-1];
       // cout<<temp<<endl;
        arr.pop_back();
        return temp;
    }
    
    void increment(int k, int val) {
        int j = 0;
        if(k < arr.size()) 
            j = k;
        else
            j = arr.size();
        
        for(int i=0;i<j;i++) {
       //     cout<<arr[i]<<endl;
            arr[i] += val;
         //   cout<<arr[i]<<endl;
        }
    }
};
​
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
