class Solution {
public:
    string predictPartyVictory(string senate) {
        // QUEUE problem
        // First in frist out principle
        // counter for Rs
        // counter for Ds
        // Condition, while R != 0 or D != 0
        /*
        vector<int> letters;
        int numRs{0};
        int numDs{0};
        int numActiveDs{0};
        int numActiveRs{0};
        int pointer{0};
        while(letters.size() == 0 || (numRs != 0 && numDs != 0)){
            std::cout<<senate<<std::endl;
            for(int i{0}; i < senate.size(); i++){
                if(senate[i] == 'R'){
                    if(numActiveDs > 0){
                        numActiveDs--;
                    } else if(numDs > 0){
                        numDs--;
                        letters.push_back('R');
                        numRs++;
                    } else {
                        letters.push_back('R');
                        numRs++;
                        numActiveRs++;
                    }
                } else {
                    if(numActiveRs > 0){
                        numActiveRs--;
                    } else if(numRs > 0){
                        numRs--;
                        letters.push_back('D');
                        numDs++;
                    } else {
                        letters.push_back('D');
                        numDs++;
                        numActiveDs++;
                    }
                }
            }
            senate = "";
            //int numRemainingRs{0};
            //int numRemainingDs{0};
            for(int i{0}; i <letters.size(); i++){
                /*if(letters[i] == 'R'){
                    numRemainingRs++;
                } else {
                    numRemainingDs++;
                }
                senate += letters[i];
            }
        }
        if(numRs > 0){
            return "Radiant";
        } else {
            return "Dire";
        }*/

        // Second attempt
        queue<int> Rs;
        queue<int> Ds;
        int n = senate.size();
        for(int i{0}; i < n; i++){
            if(senate[i] == 'R'){
                Rs.push(i);
            } else{
                Ds.push(i);
            }
        }

        while(Rs.size() != 0 && Ds.size() != 0){
            if(Rs.front() < Ds.front()){
                int newIndex = Rs.front() + n;
                Rs.pop();
                Ds.pop();
                Rs.push(newIndex);
            } else {
                int newIndex = Ds.front() + n;
                Ds.pop();
                Rs.pop();
                Ds.push(newIndex);
            }
        }

        return Rs.size() == 0 ? "Dire" : "Radiant";
    }
};

// O(n) run time, since we just iterate through the array once,
// And then keep adding
// o(1) pop and push
// O(n) memory

//RDDRRDRDRDDRDRDR
// D 
// R
// RR
// RD
// RR
// RD
//"DRRDRDRDRDDRDRDR"
//
