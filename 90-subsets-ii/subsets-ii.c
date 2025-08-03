// Comparator for qsort
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// Recursive helper for generating subsets (skipping duplicates)
void recHelper(int arr[], int size, int** res, int* resSize, int* colSizes, int* temp, int tempIndex, int currIndex)
{
    // Save the current subset
    res[*resSize] = malloc(tempIndex * sizeof(int));
    for(int i = 0; i < tempIndex; i++)
    {
        res[*resSize][i] = temp[i];
    }
    colSizes[*resSize] = tempIndex;
    (*resSize)++;

    for(int i = currIndex; i < size; i++)
    {
        // Skip duplicates at the same recursion depth
        if(i > currIndex && arr[i] == arr[i - 1])
        {
            continue;
        }
        temp[tempIndex] = arr[i];
        recHelper(arr, size, res, resSize, colSizes, temp, tempIndex + 1, i + 1);
    }
}

// Main function for Subsets II (with duplicates)
int** subsetsWithDup(int arr[], int size, int* returnSize, int** returnColumnSizes)
{
    qsort(arr, size, sizeof(int), compare); // Sort to handle duplicates
    int len = 1 << size; // Max possible subsets = 2^n
    int** res = malloc(len * sizeof(int*));
    int* colSizes = malloc(len * sizeof(int));
    int* temp = malloc(size * sizeof(int));
    *returnSize = 0;

    recHelper(arr, size, res, returnSize, colSizes, temp, 0, 0);

    *returnColumnSizes = colSizes;
    free(temp);
    return res;
}