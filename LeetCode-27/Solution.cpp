//
// Date: 2026/3/8
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[len++] = nums[i];

        return len;
    }
};

int main() {

    vector<int> nums = {3,2,2,3};
    int val = 3;

    Solution solution;
    int len = solution.removeElement( nums, val );

    for (int i = 0; i < len; i++)
        cout << nums[i] << " ";

    return 0;
}
