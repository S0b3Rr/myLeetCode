class Solution {
public:
    string interpret(string command) {
            string anss = "";
            for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                anss += command[i];
            }
            if (command[i] == '(' && command[i + 1] == ')') {
                anss += "o";
            }
            if (command[i] == '(' && command[i + 1] == 'a') {
                anss += "al";
            }
        }
        return anss;
    }
};