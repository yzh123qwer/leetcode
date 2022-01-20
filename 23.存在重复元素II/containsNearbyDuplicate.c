/*219. 存在重复元素 II
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

 

示例 1：

输入：nums = [1,2,3,1], k = 3
输出：true
示例 2：

输入：nums = [1,0,1,1], k = 1
输出：true
示例 3：

输入：nums = [1,2,3,1,2,3], k = 2
输出：false
*/
struct hashTable{
    int val;
    int j;
};
//使得每个列表中存储对应的值，和该值的位置
int hash(int a, int tableSize){
    return a * a % tableSize;
}
struct hashTable* Initialize(int tableSize){
    struct hashTable* h;
    h = (struct hashTable*)malloc(sizeof(struct hashTable) * tableSize);
    int i;
    for (i = 0; i < tableSize; i++)
        h[i].j = -1;//位置初始化为-1，表示还没有放入元素
    return h;
}
void Insert(struct hashTable* H, int val, int i, int tableSize){
    int val_hash;
    val_hash = hash(val, tableSize);
    if (H[val_hash].j == -1){
        H[val_hash].j = i;
        H[val_hash].val = val;
        return;
    }
    else{
        int m;
        for (m = 0; val_hash + m < tableSize && (H[val_hash + m].j != -1 && H[val_hash + m].val != val); m++);
        if (val_hash + m == tableSize){
            for (m = 0; H[m].j != -1; m++);
            H[m].val = val;
            H[m].j = i;
            return;
        }
        else{
            H[val_hash + m].val = val;
            H[val_hash + m].j = i;
            return;
        }
    }
}
int find(struct hashTable* H, int val, int tableSize){
    int val_hash = hash(val, tableSize);
    if (H[val_hash].j == -1){
        return -1;//表示没有该元素
    }
    else {
        if (H[val_hash].val == val)
            return H[val_hash].j;//找到则直接返回上一次的位置
        else{
            int m;
            for (m = 0; val_hash + m < tableSize && H[val_hash + m].val != val; m++);
            if (val_hash + m == tableSize){
                for (m = 0; H[m].val != val; m++);
                return H[m].j;
            }
            else{
                return H[val_hash + m].j;
            }
        }
    }
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    int tableSize = numsSize * 2;
    struct hashTable *T = NULL;
    T = Initialize(tableSize);
    int i, j_tmp;
    for (i = 0; i < numsSize; i++){
        j_tmp = find(T, nums[i], tableSize);
        if (j_tmp == -1){
            Insert(T, nums[i], i, tableSize);
            continue;
        }
        else{
            if (i - j_tmp <= k)
                return true;
            else{
                Insert(T, nums[i], i, tableSize);
                continue;
            }
        }
    }
    return false;
}
