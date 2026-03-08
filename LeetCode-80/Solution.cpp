//
// Date: 2026/3/8
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates1(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (len < 2 || nums[i] != nums[len - 2]) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
    int removeDuplicates(vector<int>& nums) {
        int len = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[len - 2]) {
                nums[len++] = nums[i];
            }
        }
        return len<nums.size()? len:nums.size();
    }
};


int main() {
    vector<int> nums = {1,1,1,2,2,3};

    Solution solution;
    int len = solution.removeDuplicates( nums );

    for ( int i=0 ; i<len ; i++ )
        cout << nums[i] << " ";

    return 0;
}


