#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int tableSize = nums.size();
        struct hashTable* T = NULL;
        T = Initialize(tableSize);
        int i, j_tmp;
        for (i = 0; i < nums.size(); i++) {
            j_tmp = find(T, nums[i], tableSize);
            if (j_tmp == -1) {
                Insert(T, nums[i], i, tableSize);
                continue;
            }
            else {
                if (i - j_tmp <= k)
                    return true;
                else {
                    Insert(T, nums[i], i, tableSize);
                    continue;
                }
            }
        }
        return false;
    }
private:
    struct hashTable {
        int val;
        int j;
    };
    int hash(int a, int tableSize) {
        return a * a % tableSize;
    }//简单的散列函数
    struct hashTable* Initialize(int tableSize) {
        struct hashTable* h;
        h = (struct hashTable*)malloc(sizeof(struct hashTable) * tableSize);
        int i;
        for (i = 0; i < tableSize; i++)
            h[i].j = -1;//位置初始化为-1，表示还没有放入元素
        return h;
    }//创建一个散列表
    void Insert(struct hashTable* H, int val, int i, int tableSize) {
        int val_hash;
        val_hash = hash(val, tableSize);
        if (H[val_hash].j == -1) {
            H[val_hash].j = i;
            H[val_hash].val = val;
            return;
        }
        else {
            int m;
            for (m = 0; val_hash + m < tableSize && (H[val_hash + m].j != -1 && H[val_hash + m].val != val); m++);
            if (val_hash + m == tableSize) {
                for (m = 0; H[m].j != -1; m++);
                H[m].val = val;
                H[m].j = i;
                return;
            }
            else {
                H[val_hash + m].val = val;
                H[val_hash + m].j = i;
                return;
            }
        }
    }
    int find(struct hashTable* H, int val, int tableSize) {
        int val_hash = hash(val, tableSize);
        if (H[val_hash].j == -1) {
            return -1;//表示没有该元素
        }
        else {
            if (H[val_hash].val == val)
                return H[val_hash].j;//找到则直接返回上一次的位置
            else {
                int m;
                for (m = 0; val_hash + m < tableSize && H[val_hash + m].val != val; m++);
                if (val_hash + m == tableSize) {//位置超过散列表大小
                    for (m = 0; H[m].val != val; m++);//从起始地址重新寻找
                    return H[m].j;
                }
                else {
                    return H[val_hash + m].j;
                }
            }
        }
    }
};
int main() {
    Solution A;
    vector<int> a = { 1, 2, 3, 1 };
    cout << A.containsNearbyDuplicate(a, 3) << endl;
}
