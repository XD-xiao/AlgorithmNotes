//
// Date: 2026/3/8
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=0 , votes = 0 , count = 0;
        for ( int i=0 ; i<nums.size() ; i++) {
            if ( votes == 0)
                x = nums[i];
            votes += (nums[i] == x) ? 1 : -1;
        }

        // 统计验证
        // for (int num : nums)
        //     if (num == x) count++;

        return x;
    }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};

    Solution solution;
    int len = solution.majorityElement( nums );

    cout << len << endl;
    return 0;
}
