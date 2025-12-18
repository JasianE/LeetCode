#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // O(n) time
        //Once we enter a bracket then we dont
        //Change any other brackets avlues until
        //We find the other bracket
        
        stack<char> lhs;

        int index{0};
        while(s[index] != '\0'){
            if(s[index] == '(' || s[index] == '[' || s[index] == '{'){
                lhs.push(s[index]);
            } else{
                if(lhs.size() == 0){
                    return false;
                }
                char res{lhs.top()};
                lhs.pop();
                if(s[index] == ')'){
                    if(res != '('){
                        return false;
                    } 
                } else if(s[index] == ']'){
                    if(res !='['){
                        return false;
                    }
                } else if(s[index] == '}'){
                    if(res !='{'){
                        return false;
                    }
                }
                
            }
            index++;
        }

        if(lhs.size() > 0){
            return false;
        }
        return true;
    }
};