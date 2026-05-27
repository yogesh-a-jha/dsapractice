//using sorting
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int candidate = nums[nums.size()/2];
    int count = 0;

    for(int x : nums){
        if(x == candidate)
            count++;
    }

    if(count > nums.size()/2)
        return candidate;

    return -1;
}



//using moore's voting algorithm
int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for(int num : nums) {
        if(count == 0)
            candidate = num;

        if(num == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}