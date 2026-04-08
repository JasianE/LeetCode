// yo am i getting better at ts?

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Focus on popping on ONE SIDE ONLY, meaning that if we see a negative, for example, then we pop on the ones to the LEFT, and we do nothing for
        // the positives
        // Idea;
        // Keep pushing asteroids w/ a positive value
        // if its a negative, then we pop untill either it is the only one left, or it is destroyed.
      //O(n) run time
      // o(n) space

        vector<int> myStack;

        for(int i{0}; i < asteroids.size(); i++){
            if(asteroids[i] >0){
                myStack.push_back(asteroids[i]);
            } else{
                while(myStack.size() > 0 && myStack[myStack.size()-1] > 0 && myStack[myStack.size()-1] < asteroids[i] * -1 ){
                    myStack.pop_back();
                }
                if(myStack.size() == 0){
                    myStack.push_back(asteroids[i]);
                } else if(myStack[myStack.size()-1] < 0){
                    myStack.push_back(asteroids[i]);
                }
                else if(myStack[myStack.size()-1] == asteroids[i] * -1){
                    myStack.pop_back();
                }
                
            }
        }

        return myStack;
    }
};

