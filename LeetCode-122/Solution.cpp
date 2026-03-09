//
// Date: 2026/3/9
//
//
// Date: 2026/3/9
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i=0 ; i<prices.size()-1 ; i++)
            if (prices[i+1] > prices[i]) {
                profit += prices[i+1] - prices[i];
            }

        return profit;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {1,2};
    // vector<int> nums = {2,4,1};

    Solution solution;
    int profit = solution.maxProfit( nums );

    cout << profit << endl;
    return 0;
}