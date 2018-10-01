//
// Created by 懒小植 on 2018/10/2.
//

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        vector<int> merge;
        if (nums1.empty()) {
            merge = nums2;
        }
        if (nums2.empty()) {
            merge = nums1;
        }
        if (!nums1.empty() && !nums2.empty()) {
            int i = 0, j = 0;
            while(i < nums1.size() && j < nums2.size()){
                if (nums1[i] < nums2[j]) {
                    merge.push_back(nums1[i]);
                    i++;
                }
                else {
                    merge.push_back(nums2[j]);
                    j++;
                }
            }
            if (i < nums1.size()) {
                for (int k = i; k < nums1.size(); k++) {
                    merge.push_back(nums1[k]);
                }
            }
            if (j < nums2.size()) {
                for (int k = j; k < nums2.size(); k++) {
                    merge.push_back(nums2[k]);
                }
            }
        }
        if (totalSize % 2 == 0) {
            return (merge[totalSize / 2 - 1] + merge[totalSize / 2]) * 1.0 / 2;
        }
        else {
            return merge[(totalSize - 1) / 2];
        }
    }
};