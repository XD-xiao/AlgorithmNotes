//
// Date: 2026/3/10
//
#include<bits/stdc++.h>
using namespace std;
class RandomizedSet {
private:
    unordered_map<int,int> hash;    //哈希表储存元素值和对应下标，为了remove时实现O（1）
    vector<int> dyArray;        //vector可以作为动态数组，实现getRandom和insert的常数时间操作

public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = hash.find(val);
        if(it != hash.end()) return false;  //如果集合中已经存在val，返回false，节省时间
        dyArray.push_back(val);
        hash[val] = dyArray.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = hash.find(val);
        if(it == hash.end()) return false;  //删除时，如果集合中不存在val，返回false

        int lastPos = dyArray.size() - 1;   //将被删除值和数组最后一位进行交换
        int valPos = hash[val];
        dyArray[valPos] = dyArray[lastPos];
        dyArray.pop_back();                 //vector数组删除val
        hash[dyArray[valPos]] = valPos;     //被交换的值下标发生变化，需要更新
        hash.erase(val);                    //哈希表中删除val的项
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int size = dyArray.size();
        int pos = rand()%size;  //对下标产生随机数
        return dyArray[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {

    // ["RandomizedSet","remove","remove","insert","getRandom","remove","insert"]
    // [[],[0],[0],[0],[],[0],[0]]


    RandomizedSet randomizedSet;
    cout << randomizedSet.remove(0) << endl;
    cout << randomizedSet.remove(0) << endl;
    cout << randomizedSet.insert(0) << endl;
    cout << randomizedSet.getRandom()   << endl;
    cout << randomizedSet.remove(0) << endl;
    cout << randomizedSet.insert(0) << endl;



    // RandomizedSet randomizedSet;
    // cout << randomizedSet.insert(1) << endl; // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    // cout << randomizedSet.remove(2) << endl; // 返回 false ，表示集合中不存在 2 。
    // cout << randomizedSet.insert(2) << endl; // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    // cout << randomizedSet.getRandom()   << endl; // getRandom 应随机返回 1 或 2 。
    // cout << randomizedSet.remove(1) << endl; // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    // cout << randomizedSet.insert(2) << endl; // 2 已在集合中，所以返回 false 。
    // cout << randomizedSet.getRandom()   << endl; // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。


    return 0;
}