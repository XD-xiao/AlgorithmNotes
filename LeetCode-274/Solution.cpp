//
// Date: 2026/3/10
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n + 1);
        for (auto c : citations) {
            cnt[min(c, n)]++; // 引用次数 > n，等价于引用次数为 n
        }
        int s = 0;
        for (int i = n; ; i--) { // i=0 的时候，s>=i 一定成立
            s += cnt[i];
            if (s >= i) { // 说明有至少 i 篇论文的引用次数至少为 i
                return i;
            }
        }
    }
};

int main() {
    vector<int> nums = {3,0,6,1,5};

    Solution solution;
    int res = solution.hIndex( nums );

    cout << res << endl;
    return 0;
}