class Solution {
public:
    string decodeString(string s) {
        string output;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                output.push_back(s[i]);
            } else {
                // Step 1: build substring inside [...]
                string substr = "";
                while (!output.empty() && output.back() != '[') {
                    substr = output.back() + substr;
                    output.pop_back();
                }

                // remove '['
                output.pop_back();

                // Step 2: get the number before '['
                string numStr = "";
                while (!output.empty() && isdigit(output.back())) {
                    numStr = output.back() + numStr;
                    output.pop_back();
                }

                int number = stoi(numStr);

                // Step 3: repeat substring
                for (int j = 0; j < number; j++) {
                    output += substr;
                }
            }
        }
        return output;
    }
};
