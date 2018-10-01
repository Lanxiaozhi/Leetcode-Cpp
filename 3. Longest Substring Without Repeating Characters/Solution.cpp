//
// Created by 懒小植 on 2018/10/2.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 2){
            return s.length();
        }
        int maxLen = 1;
        string str;
        for(int i=0;i<s.length()-1;i++){
            str.clear();
            str = str + s[i];
            for(int j=i+1;j<s.length();j++){
                if(str.find(s[j]) == -1){
                    str = str + s[j];
                }
                else{
                    if(str.length() > maxLen){
                        maxLen = str.length();
                    }
                    str.clear();
                    break;
                }
            }
            if(str.length() > maxLen){
                maxLen = str.length();
            }
        }
        if(str.length() > maxLen){
            maxLen = str.length();
        }
        return maxLen;
    }
};