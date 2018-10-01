//
// Created by 懒小植 on 2018/10/2.
//

class Solution {
public:
    string intToRoman(int num) {
        string result;
        vector<int> Val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> Roman{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i=0;i<Roman.size();i++){
            while(num >= Val[i]){
                num -= Val[i];
                result += Roman[i];
            }
        }
        return result;
    }
};