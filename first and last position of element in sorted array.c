/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binarySearch(int* nums, int numsSize, int target, int findFirst){
    int left = 0, right = numsSize - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            if (findFirst)
                right = mid - 1;
            else
                left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    int first = binarySearch(nums, numsSize, target, 1);
    int last = binarySearch(nums, numsSize, target, 0);

    result[0] = first;
    result[1] = last;

    return result;
}
