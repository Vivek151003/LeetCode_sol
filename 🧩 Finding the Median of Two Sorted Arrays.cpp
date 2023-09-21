// Intuition
// Merging two sorted arrays involves efficiently combining the elements from both arrays while maintaining the sorted order.
// **Finding the Median of a Sorted Array

// Intuition:**
// To find the median of a sorted array, you need to consider whether the array has an even or odd number of elements and then compute the median accordingly.

// Approach
// Initialize three pointers: i for the first array, j for the second array, and k for the merged array.

// Compare the elements at nums1[i] and nums2[j], and place the smaller element in the merged array res[res]. Increment the pointer for the array from which you took the element (i or j) and the k pointer.

// Continue this process until you have merged all elements from both arrays.

// If there are remaining elements in either nums1 or nums2, add them to the merged array.

// Calculate the total number of elements in the merged array, which is the sum of the lengths of nums1 and nums2.

// If the total number of elements is odd (size % 2 == 1), return the middle element, which is res[size / 2].

// If the total number of elements is even (size % 2 == 0), compute the average of the two middle elements, which are res[size / 2] and res[(size / 2) - 1]. Return (res[size / 2] + res[(size / 2) - 1]) / 2.0.

// Complexity
// Time complexity:
// O(n)

// Space complexity:
// O(n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0, k = 0;
        vector<int> res(n1 + n2);

        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                res[k] = nums1[i];
                i++;
            } else {
                res[k] = nums2[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            res[k] = nums1[i];
            i++;
            k++;
        }

        while (j < n2) {
            res[k] = nums2[j];
            j++;
            k++;
        }

        int size = n1 + n2;
        if (size % 2 == 1) {
            return res[size / 2];
        } else {
            return (res[size / 2] + res[(size / 2) - 1]) / 2.0;
        }
    }
}; 

// Approach 2 : O(1) space complexity
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0, k = 0;
        int size = n1+n2;
        int idx1 = size/2;
        int element1;
        int idx2 = size/2 - 1;
        int element2;
        while (i < n1 && j < n2) {
            if(nums1[i] < nums2[j])
            {
                if(k == idx1)
                {
                    element1 = nums1[i];
                }
                if(k == idx2)
                {
                    element2 = nums1[i];
                }
                i++;
            }
            else
            {
                if(k == idx1)
                {
                    element1 = nums2[j];
                }
                if(k == idx2)
                {
                    element2 = nums2[j];
                }
                j++;
            }
            k++;
        }

        while (i < n1) {
            if(k == idx1)
                {
                    element1 = nums1[i];
                }
                if(k == idx2)
                {
                    element2 = nums1[i];
                }
                i++;
                k++;
        }

        while (j < n2) {
            if(k == idx1)
                {
                    element1 = nums2[j];
                }
                if(k == idx2)
                {
                    element2 = nums2[j];
                }
                j++;
                k++;
        }
        if (size % 2 == 1) {
            return element1;
        } else {
            return (element1 + element2)/ 2.0;
        }
    }
};
