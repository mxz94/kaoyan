#include <stdio.h>

void bubble_sort(int a[], int n) {

    int sign = 0;
    for (int i = n-1; i > 0; i--)
    {
        sign = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j+1]) {
                sign = 1;
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
        if (sign == 0) {
            break;
        }
    }
    return a;

}

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int i,j,x;
        i = l;
        j = r;
        x = a[i];
        while (i < j)
        {
            while(i < j && a[j] > x)
                j--; // 从右向左找第一个小于x的数
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i] < x)
                i++; // 从左向右找第一个大于x的数
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        quick_sort(a, l, i-1); /* 递归调用 */
        quick_sort(a, i+1, r); /* 递归调用 */
    }

}

//  遍历剩下未排序的插入遍历已排序的中
void insert_sort(int a[], int n) {
    int i, j, k;

    for (i = 1; i < n; i++)
    {
        //为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置
        for (j = i - 1; j >= 0; j--)
            if (a[j] < a[i])
                break;

        //如找到了一个合适的位置
        if (j != i - 1)
        {
            //将比a[i]大的数据向后移
            int temp = a[i];
            for (k = i - 1; k > j; k--)
                a[k + 1] = a[k];
            //将a[i]放到正确位置上
            a[k + 1] = temp;
        }
    }

}

//  两轮循环每次找出最小的值进行替换, 交换次数较于 冒泡少
void select_sort(int a[], int n) {
    int i;        // 有序区的末尾位置
    int j;        // 无序区的起始位置
    int min;    // 无序区中最小元素位置

    for(i=0; i<n; i++)
    {
        min=i;

        // 找出"a[i+1] ... a[n]"之间的最小元素，并赋值给min。
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[min])
                min=j;
        }

        // 若min!=i，则交换 a[i] 和 a[min]。
        // 交换之后，保证了a[0] ... a[i] 之间的元素是有序的。
        if(min != i)
            swap(a[i], a[min]);
    }
}

void merge_sort(int a[], int start, int mid, int end) {
    int *tmp = (int*)malloc((end-start+1)*sizeof(int));
    int i = start;
    int j = mid + 1;
    int k = 0;

    //  排序
    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while (i <= mid)
    {
        tmp[k++] = a[i++];
    }
    while (j <= mid)
    {
        tmp[k++] = a[j++];
    }

    //  合并赋值进去
    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];

    free(tmp);
    
}

void merge_sort_up2Town(int a[], int start, int end) {
    if (a == NULL || start >= end)
        return;
    
    int mid = (end + start)/2;
    //  分 
    merge_sort_up2Town(a, start, mid);
    merge_sort_up2Town(a, mid, end);

    // 合并
    merge_sort(a, start, mid, end);
}

void merge_groups(int a[], int len, int gap)
{
    int i;
    int twolen = 2 * gap;    // 两个相邻的子数组的长度

    // 将"每2个相邻的子数组" 进行合并排序。
    for(i = 0; i+2*gap-1 < len; i+=(2*gap))
    {
        merge(a, i, i+gap-1, i+2*gap-1);
    }

    // 若 i+gap-1 < len-1，则剩余一个子数组没有配对。
    // 将该子数组合并到已排序的数组中。  奇数组
    if ( i+gap-1 < len-1)
    {
        merge(a, i, i + gap - 1, len - 1);
    }
}


void merge_sort_down2up(int a[], int len) {
    int n;

    if (a == NULL || len <=0) 
        return ;
    for ( n=1; n < len;  n*=2)
    {
        merge_groups(a, len, n);
    }
    
}

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3};
    int s = a[1];
    int *p = &a[1];
    a[1] = 3;
    printf("%d",s);
    printf("%d",*p);
    return 0;
}
