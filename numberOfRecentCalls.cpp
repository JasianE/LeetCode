class RecentCounter {
public:
    queue<int> counter;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        // brute fprce, slow
        /*
        this->counter.push_back(t);
        int num_reqs{0};
        for(int i{0}; i < counter.size(); i++){ // use a quueue i guess
            if(counter[i] >= (t - 3000) && counter[i] <= t){
                num_reqs++;
            }
        }
        return num_reqs;
        */
        // Queue method
        counter.push(t);
        while(counter.size() != 0 && counter.front() < t - 3000){
            counter.pop();
        }
        return counter.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
