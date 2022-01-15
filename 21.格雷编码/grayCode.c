/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int n2(int n){//返回2的n次方
    int i, a = 1;
    for (i = 0; i < n; i++)
        a = a * 2;
    return a;
}
int* grayCode(int n, int* returnSize){
    if (n == 0){
        *returnSize = 1;
        int* a = (int*)malloc(sizeof(int));
        *a = 0;
        return a;
    }
    else if (n == 1){
        *returnSize = 2;
        int* b = (int*)malloc(sizeof(int) * 2);
        b[0] = 0;
        b[1] = 1;
        return b; 
    }
    else{
        *returnSize = n2(n);
        int* gray_n1, *gray_n2 = NULL;
        int size_n1, size_n2;
        size_n1 = n2(1);
        gray_n1 = (int*)malloc(sizeof(int) * size_n1);
        gray_n1[0] = 0;
        gray_n1[1] = 1;
        int i, j, k;
        for (i = 2; i <= n; i++){
            size_n2 = n2(i);
            gray_n2 = (int*)malloc(sizeof(int) * size_n2);
            for (j = 0, k = 0; j < size_n1; j++){
                gray_n2[k++] = gray_n1[j];
                gray_n2[k++] = gray_n1[j++] + size_n1;
                gray_n2[k++] = gray_n1[j] + size_n1;
                gray_n2[k++] = gray_n1[j];
            }
            free(gray_n1);
            gray_n1 = gray_n2;
            size_n1 = size_n2;
        }
        return gray_n2;
    }
}
