#include <string>
using namespace std; 

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // We know that the maximum / longest will always be one or the other of the two strings
        // So we can go up incrementally up each letter of the shortest word, and see if we can loop through
        /*
        try all prefixes, and we can determine how much we add up

        */

        // What is the algorithm here?
        // BRUTE FORCE
        //Start off with the first letter of the shorter string
        // Add it up to the amount required to match the second string, if it works, try it out on the next one
        // If it doesn't work, move on to the next one that can be divisible 
        // keep track of which ones owork and dont
        //O(n^2), have to loop through the array twice each time
        string substring;
        if(str1.size() > str2.size()){
            // Check the string length
            substring = str2; 
            while(substring.size() > 0){
                if(str1.size()%substring.size() == 0 && str2.size()%substring.size() == 0){
                    unsigned long times_to_copy{str2.size()/ substring.size()}; //size returns unsized long, remember
                    unsigned long times_to_copy_for_second_string{str1.size() / substring.size()};
                    string to_copy = "";
                    string second_to_copy ="";
                    for(int i{0}; i < times_to_copy; i++){
                        to_copy = to_copy + substring;
                    }
                    for(int i{0}; i < times_to_copy_for_second_string; i++){
                        second_to_copy = second_to_copy + substring;
                    }
                    if(to_copy.compare(str2) == 0 && second_to_copy.compare(str1) == 0){
                        return substring; 
                    }
                } 
                substring.pop_back();
            }
        } else {
            substring = str1; 
            while(substring.size() > 0){
                if(str1.size()%substring.size() == 0 && str2.size()%substring.size() == 0){
                    unsigned long times_to_copy{str1.size()/ substring.size()};
                    unsigned long times_to_copy_for_second_string{str2.size() / substring.size()};
                    string to_copy = "";
                    string second_to_copy ="";
                    for(int i{0}; i < times_to_copy; i++){
                        to_copy = to_copy + substring;
                    }
                    for(int i{0}; i < times_to_copy_for_second_string; i++){
                        second_to_copy = second_to_copy + substring;
                    }
                    if(to_copy.compare(str1) == 0 && second_to_copy.compare(str2) == 0){
                        return substring; 
                    }
                } 
                substring.pop_back();
            }
        }

        return "";
    }
};