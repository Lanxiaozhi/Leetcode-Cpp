//
// Created by 懒小植 on 2018/10/2.
//

class Solution {
public:
    bool isRecall(string s){
        if(s.length()<=0){
            return false;
        }
        for(int i=0;i<s.length();i++){
            int j = s.length() - i - 1;
            if(i >= j){
                return true;
            }
            else if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s) {
        string resStr = "";
        if (s.length() == 1) {
            return s;
        }
        for (int i = 0; i<s.length(); i++) {
            for (int j = 1; j<s.length() + 1 - i; j++) {
                if(j < resStr.length()){
                    continue;
                }
                string str = s.substr(i, j);
                if (isRecall(str)) {
                    if (str.length() > resStr.length()) {
                        resStr = str;
                    }
                }
            }
        }
        return resStr;
    }
};