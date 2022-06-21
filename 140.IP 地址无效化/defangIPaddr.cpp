/*
1108. IP 地址无效化
给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。

所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

 

示例 1：

输入：address = "1.1.1.1"
输出："1[.]1[.]1[.]1"
示例 2：

输入：address = "255.100.50.0"
输出："255[.]100[.]50[.]0"
*/
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (int i = 0; i < address.size(); i++){
            if (address[i] == '.'){
                ans.push_back('[');
                ans.push_back('.');
                ans.push_back(']');
            }
            else 
                ans.push_back(address[i]);
        }
        return ans;
    }
};
