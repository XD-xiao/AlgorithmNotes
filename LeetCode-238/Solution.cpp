//
// Date: 2026/3/12
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return {};
        vector<int> ans(len, 1);
        ans[0] = 1;
        int tmp = 1;
        for (int i = 1; i < len; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for (int i = len - 2; i >= 0; i--) {
            tmp *= nums[i + 1];
            ans[i] *= tmp;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};

    Solution solution;
    vector<int> res = solution.productExceptSelf(nums);

    for ( int i=0 ; i<res.size() ; i++)
        cout << res[i] << " " ;
    return 0;
}