/*
432. 全 O(1) 的数据结构
请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。

实现 AllOne 类：

AllOne() 初始化数据结构的对象。
inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
 

示例：

输入
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
输出
[null, null, null, "hello", "hello", null, "hello", "leet"]

解释
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // 返回 "hello"
allOne.getMinKey(); // 返回 "hello"
allOne.inc("leet");
allOne.getMaxKey(); // 返回 "hello"
allOne.getMinKey(); // 返回 "leet"
*/
class AllOne {
public:
    int max_nums;
    int min_nums;
    int temp_nums;
    string str_max_nums;
    string str_min_nums;
    unordered_map<string, int> hash;

    AllOne() {
        max_nums = 0;
        min_nums = 10; // 在第一次调用inc之后，会被更改为1
        temp_nums = 0;
        str_max_nums = str_min_nums = "";
        hash.clear();
    }
    
    void inc(string key) {
        if (hash.find(key) == hash.end()){
            hash.insert(make_pair(key, 1));
            temp_nums = 1;
            if (temp_nums > max_nums){
                max_nums = temp_nums;
                str_max_nums = key;
            }
            if (temp_nums < min_nums){
                min_nums = 1;
                str_min_nums = key;
            }
            return;
        }
        else {
            temp_nums = ++(hash.find(key)->second);
            if (temp_nums > max_nums){
                max_nums = temp_nums;
                str_max_nums = key;
            }
            if (str_min_nums == key){
                int j = 0;
                for (auto i : hash){
                    if (j == 0){
                        min_nums = i.second;
                        str_min_nums = i.first;
                    }
                    temp_nums = i.second;
                    if (temp_nums < min_nums){
                        min_nums = temp_nums;
                        str_min_nums = i.first;
                    }
                    j++;
                }
            }
        }
    }
    
    void dec(string key) {
        if (hash.find(key)->second == 1){
            hash.erase(hash.find(key));
            if (str_min_nums == key){
                int j = 0;
                for (auto i : hash){
                    if (j == 0){
                        min_nums = i.second;
                        str_min_nums = i.first;
                    }
                    temp_nums = i.second;
                    if (temp_nums < min_nums){
                        min_nums = temp_nums;
                        str_min_nums = i.first;
                    }
                    j++;
                }
            }
            if (str_max_nums == key){
                int j = 0;
                for (auto i : hash){
                    if (j == 0){
                        max_nums = i.second;
                        str_max_nums = i.first;
                    }
                    temp_nums = i.second;
                    if (temp_nums > max_nums){
                        max_nums = temp_nums;
                        str_max_nums = i.first;
                    }
                    j++; 
                }
            }
        }
        else {
            hash.find(key)->second--;
            if (str_max_nums == key){
                int j = 0;
                for (auto i : hash){
                    if (j == 0){
                        max_nums = i.second;
                        str_max_nums = i.first;
                    }
                    temp_nums = i.second;
                    if (temp_nums > max_nums){
                        max_nums = temp_nums;
                        str_max_nums = i.first;
                    }
                    j++; 
                }
            }
            if (str_min_nums == key){
                int j = 0;
                for (auto i : hash){
                    if (j == 0){
                        min_nums = i.second;
                        str_min_nums = i.first;
                    }
                    temp_nums = i.second;
                    if (temp_nums < min_nums){
                        min_nums = temp_nums;
                        str_min_nums = i.first;
                    }
                    j++;
                }
            }
        }
    }
    
    string getMaxKey() {
        return str_max_nums;
    }
    
    string getMinKey() {
        return str_min_nums;
    }
};
