int minNumberInRotateArray(int* rotateArray, int rotateArrayLen ) {
    int i = 0;
    for(i = 0; i + 1 < rotateArrayLen; i++)
    {
        if(*(rotateArray + i) > *(rotateArray + i + 1))
            return *(rotateArray + i + 1);
    }
    return *rotateArray;
}
