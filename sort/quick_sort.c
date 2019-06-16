#include <stdio.h>
#include "quick_sort.h"

void quick_sort(int *parr, int len)
{
    int i = 0, j = len-1;
    int flag = 0;

    //只有一个数, 不用再排序
    if(i >= j) {
	return;
    }

    flag = parr[0];
    while(i < j) {
	//向右找到第一个比基准值小的数
	while( (parr[j] >= flag) && (i < j) ) {
	    --j;
	}
	
	//向左找到第一个比基准值大的数
	while( (parr[i] <= flag) && (i < j) ) { 
	    ++i;
	}

	if(i < j) {
	    parr[i] ^= parr[j];
	    parr[j] ^= parr[i];
	    parr[i] ^= parr[j];
	}
    }
    
    parr[0] = parr[i];
    parr[i] = flag;

    //排序左边，从0开始，长度是i
    quick_sort(parr, i);
    //排序右边，从i+1开始，第i位作为基准数，不需再排序
    quick_sort(parr+i+1, len - i - 1);
}

void print_arr(int *parr, int arr_len)
{
    int index = 0;
    for(index = 0; index < arr_len; ++index) {
	printf("%d ", parr[index]); 
    }   
    printf("\n");
}   

