int NumberOf1(int n) {
    int i, count = 0;
    for(i = 0; i < 32; i++)
    {
        if(((n >> i) & 1) == 1)
            count++;
    }
    return count;
}
