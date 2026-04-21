void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int findKthLargest(int* nums, int numsSize, int k) {
    srand(time(NULL));
    int target = numsSize - k;

    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];

        int i = left, lt = left, gt = right;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(&nums[i], &nums[lt]);
                i++; lt++;
            } else if (nums[i] > pivot) {
                swap(&nums[i], &nums[gt]);
                gt--;
            } else {
                i++;
            }
        }

        if (target < lt)
            right = lt - 1;
        else if (target > gt)
            left = gt + 1;
        else
            return nums[target];
    }

    return -1;
}