#include "quick_sort.h"

int main()
{
    int arr_len = 0;
    int arr[] = { 5,4,6,8,10,0,3 };

    arr_len = sizeof(arr)/sizeof(arr[0]);

    print_arr(arr, arr_len);
    quick_sort(arr, arr_len);
    print_arr(arr, arr_len);

    return 0;
}

