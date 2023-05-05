#include <stdio.h>


// 冒泡排序
void bubbleSort(int arr[], int len) {
    int i, j, temp;
    int flag;
    //  i 代表 最外层
    for (i = len - 1 ; i > 0; i--) {
        flag = 0;
//        j代表内层循环   i 在慢慢收缩
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;   // 此遍循环没有交换，说明已经有序
        }
    }
}

// 选择排序
void selectSort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 插入排序
void insertSort(int arr[], int len) {
    int i, j, temp;
    for (i = 1; i < len; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

// 快速排序
void quickSort(int arr[], int left, int right) {
    int i, j, temp;
    if (left > right) {
        return;
    }
    temp = arr[left];
    i = left;
    j = right;
    while (i != j) {
        while (arr[j] >= temp && i < j) {
            j--;
        }
        while (arr[i] <= temp && i < j) {
            i++;
        }
        if (i < j) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[left] = arr[i];
    arr[i] = temp;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

// 归并排序
void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[right - left + 1];
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

// 递归使用归并排序，对arr[left...right]的范围进行排序
void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    if (arr[mid] > arr[mid + 1]) {
        merge(arr, left, mid, right);
    }
}
int main() {
    printf("Hello, World!\n");
    return 0;
}
