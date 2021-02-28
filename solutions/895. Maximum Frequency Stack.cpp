class FreqStack {
public:
    map<int,int>freqmap;
    map<int,stack<int> > setmap;
    int maxfreq;
    FreqStack() {
        freqmap = {};
        setmap  = {};
        maxfreq = 0;
    }
    
    void push(int x) {
        int freq = freqmap[x] + 1;
        freqmap[x] = freq;
        if(freq > maxfreq)
            maxfreq = freq;
        setmap[freq].push(x);
    }
    
    int pop() {
        int top = setmap[maxfreq].top();
        setmap[maxfreq].pop();
        freqmap[top]--;
        if(setmap[maxfreq].size() == 0)
            maxfreq--;
        return top;
    }
};
​
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
