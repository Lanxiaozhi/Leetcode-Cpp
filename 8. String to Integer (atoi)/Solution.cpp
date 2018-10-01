//
// Created by 懒小植 on 2018/10/2.
//

class Solution {
public:
    int myAtoi(string str) {
        bool beginStr = false;
        bool endNum = false;
        bool isNeg = false;
        bool isOut = false;
        long result = 0;
        for (int i = 0; i<str.length(); i++) {
            if (endNum) {
                break;
            }
            else {
                if (str[i] == ' ') {
                    if (beginStr) {
                        break;
                    }
                    continue;
                }
                else {
                    if (str[i] == '-') {
                        if (!beginStr) {
                            beginStr = true;
                            isNeg = true;
                        }
                        else {
                            break;
                        }
                    }
                    else if (str[i] == '+') {
                        if (!beginStr) {
                            beginStr = true;
                            isNeg = false;
                        }
                        else {
                            break;
                        }
                    }
                    else if (str[i] >= '0' && str[i] <= '9') {
                        if (!beginStr) {
                            beginStr = true;
                        }
                        if (isNeg) {
                            if (result > (INT_MAX / 10) ||
                                (result == (INT_MAX / 10) && (str[i] - '0') > (INT_MAX % 10 + 1))) {
                                isOut = true;
                                break;
                            }
                        }
                        else {
                            if (result > (INT_MAX / 10) ||
                                (result == (INT_MAX / 10) && (str[i] - '0') > (INT_MAX % 10))) {
                                isOut = true;
                                break;
                            }
                        }
                        result = result * 10 + str[i] - '0';
                    }
                    else {
                        if (!beginStr) {
                            return 0;
                        }
                        else {
                            endNum = true;
                        }
                    }
                }
            }
        }
        if (isNeg) {
            if (isOut) {
                return INT_MIN;
            }
            return -result;
        }
        else {
            if (isOut) {
                return INT_MAX;
            }
            return result;
        }
    }
};