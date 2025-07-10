int n = arr.size();

    // Fill smaller[] such that smaller[i] stores the
    // index of a smaller element on the left side
    vector<int> smaller(n, -1);
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= arr[min])
            min = i;
        else
            smaller[i] = min;
    }

    // Fill greater[] such that greater[i] stores the
    // index of a greater element on the right side
    vector<int> greater(n, -1);
    int max = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[max])
            max = i;
        else
            greater[i] = max;
    }

    // Find the triplet
    for (int i = 0; i < n; i++)
    {
        if (smaller[i] != -1 && greater[i] != -1)
            return {arr[smaller[i]], arr[i], arr[greater[i]]};
    }

    // If no such triplet is found, return an empty vector
    return {};