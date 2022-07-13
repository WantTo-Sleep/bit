int* printNumbers(int n, int* returnSize ) {
    int i = 0;
    int num = 0;
    for(num = 1; i < n; i++)
    {
        num *= 10;
    }
    static int arr[99999] = { 0 };
    *returnSize = num - 1;
    for(i = 0; i < *returnSize; i++)
    {
        arr[i] = 1 + i;
    }
    return arr;
}
