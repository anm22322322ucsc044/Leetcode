/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct {
    int val;
    int index;
} Pair;

void merge(Pair* arr, int* counts, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    Pair* L = (Pair*)malloc(n1 * sizeof(Pair));
    Pair* R = (Pair*)malloc(n2 * sizeof(Pair));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    int rightCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            counts[L[i].index] += rightCount;
            arr[k++] = L[i++];
        } else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        counts[L[i].index] += rightCount;
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Pair* arr, int* counts, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, counts, left, mid);
    mergeSort(arr, counts, mid + 1, right);
    merge(arr, counts, left, mid, right);
}
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* counts = (int*)calloc(numsSize, sizeof(int));

    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, counts, 0, numsSize - 1);
    free(arr);

    return counts;
}/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct {
    int val;
    int index;
} Pair;

void merge(Pair* arr, int* counts, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    Pair* L = (Pair*)malloc(n1 * sizeof(Pair));
    Pair* R = (Pair*)malloc(n2 * sizeof(Pair));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    int rightCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            counts[L[i].index] += rightCount;
            arr[k++] = L[i++];
        } else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        counts[L[i].index] += rightCount;
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Pair* arr, int* counts, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, counts, left, mid);
    mergeSort(arr, counts, mid + 1, right);
    merge(arr, counts, left, mid, right);
}
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* counts = (int*)calloc(numsSize, sizeof(int));

    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, counts, 0, numsSize - 1);
    free(arr);

    return counts;
}
