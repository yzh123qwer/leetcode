class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle[0] == '\0')
            return 0;
        else{
            int m = haystack.size();
            int n = needle.size();
            vector<int> pi(n);
            int i, j;
            for (i = 1, j = 0; i < n; i++){
                while (j > 0 && needle[i] != needle[j])
                    j = pi[j - 1];
                if (needle[i] == needle[j])
                    j++;
                pi[i] = j;
            }
            int i_return;
            for (i = 0; i < m; i++){
                if (haystack[i] == needle[0]){
                    for (j = 1 ; ; j++){
                        if (haystack[i + j] == needle[j] && haystack[i + j] != '\0')
                            continue;
                        else if (needle[j] == '\0')
                            return i;
                        else{//j不是最后一个字符，并且不相同
                            if (pi[j - 1] != 0){
                                i = i + j - pi[j - 1];
                                j = pi[j - 1] - 1;
                            }
                            else
                                break;
                        }
                    }
                }
            }
            return -1;
        }
    }
};
