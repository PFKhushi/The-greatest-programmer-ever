#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *indices = (int*)malloc(sizeof(int)*2);
    int nums1[] = {1, 2, 3, 4, 5};
int target1 = 9;

int nums[] = {1, 2, 3};
int target = 4;

int nums9[] = {3, 2, 4, 9, 9, 9, 8, 22, 11};
int size = 3;
int target9 = 33;

// Test Case 2
int nums2[] = {-1, 0, 1, 2, -1, -4};
int target2 = 0;

// Test Case 3
int nums3[] = {3, 2, 4};
int target3 = 6;

// Test Case 4
int nums4[] = {0, 4, 3, 0};
int target4 = 0;

// Test Case 5
int nums5[] = {-3, 4, 3, 90};
int target5 = 0;

    int j = 0;
    for(int i=1;i<size;i++){

        if(nums[j]+nums[i]==target){

            indices[0]=j;
            indices[1]=i;
            break;
        }
        if(i==(size-1)){
            j++;
            i=j+1;
            continue;

        }


    }
    printf("%d %d\n", indices[0], indices[1]);
    return 0;
}
