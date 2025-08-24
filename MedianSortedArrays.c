double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = nums1Size, n = nums2Size;
    int merged[2000]; 
    int i = 0, j = 0, k = 0;

    
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) merged[k++] = nums1[i++];
        else merged[k++] = nums2[j++];
    }
    while (i < m) merged[k++] = nums1[i++];
    while (j < n) merged[k++] = nums2[j++];

    int total = m + n;
    if (total % 2 == 1) {
        return merged[total / 2]; 
    } else {
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0; 
    }
}