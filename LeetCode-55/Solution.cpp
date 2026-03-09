//
// Date: 2026/3/9
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k=0;
        for (int i=0 ; i<nums.size() ; i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};

    Solution solution;
    bool res = solution.canJump( nums );

    cout << res << endl;
    return 0;
}