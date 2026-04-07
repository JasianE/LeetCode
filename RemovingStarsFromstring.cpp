class Solution {
public:
    string removeStars(string s) {
        // Brute force idea:
        // Loop through array, count how many stars there are
        // use a STACK to store it onto another srting
        // if we see a star, pop, if not, keep going

        //Run time, O(n)
        // Space o(n) must create a stack
        stack<char> myStack;

        for(int i{0}; i< s.size(); i++){
            if(s[i] == '*' && myStack.size() != 0){
                std::cout<<myStack.top()<<std::endl;
                myStack.pop();
            } else {
                myStack.push(s[i]);
            }
        }

        string p = "";
        int size = myStack.size();
        for(int i{0}; i < size; i++){
            p+= myStack.top();
            myStack.pop();
        }
        reverse(p.begin(), p.end());
        return p;
    }
};
