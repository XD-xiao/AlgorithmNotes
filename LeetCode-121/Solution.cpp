//
// Date: 2026/3/9
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX, profit = 0;
        for (auto price : prices){      //使用 auto 可以自动推导容器中元素的类型，避免硬编码类型（如 int）
            profit = max(profit, price - minprice); //计算并判断 如果今天卖出 能获得的最大利润
            minprice = min(minprice, price);        //更新最低价格
        }
        return profit;
    }
};

int main() {
    vector<int> nums = {7,1,5,3,6,4};
    // vector<int> nums = {1,2};
    // vector<int> nums = {2,4,1};

    Solution solution;
    int profit = solution.maxProfit( nums );

    cout << profit << endl;
    return 0;
}