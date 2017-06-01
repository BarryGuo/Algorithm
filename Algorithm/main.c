//
//  main.c
//  Algorithm
//
//  Created by Barry on 2017/5/9.
//  Copyright © 2017年 barry. All rights reserved.
//



//#define p1   //连通性问题的快速查找解决方案,慢速并集
//#define p2  //连通性问题的快速并集解决方案
//#define p3  //连通性问题的快速并集加权算法
//#define p4 //连通性问题的对分路径压缩
//#define p5 //程序2-1  顺序搜索
//#define p6 //程序2-2  二手搜索
//#define p7  //程序3-9  循环列示例 约瑟夫问题
//#define p8  //程序3-10  表倒置
//#define p9    //程序3-11 表插入排序
//#define p10 //程序3-13 约瑟夫问题的表分配
//#define p4_1 //程序4-1 下推栈的ADT接口
//#define HeapSortT //堆排序
//#define MergeSortT //归并排序
//#define CountingSortT //计数排序
//#define RadixSortT //基数排序
//#define QuickSortT  //快速排序
#define SheelSortT  //希尔排序





#pragma mark 连通性问题的快速查找解决方案,慢速并集
#ifdef p1
#define N 10
#include <stdio.h>
int main(void) {
    // insert code here...
    int i, p, q, t, id[N];
    for (i = 0; i< N; i++) {
        id[i] = i;
    }
    
    
    while (scanf("%d %d", &p, &q) == 2) {
        if(id[p] == id[q]) continue;
        for (t=id[p], i=0; i<N; i++) {
            if(id[i] == t) id[i] = id[q];
        }
        printf("output: %d %d\n", p, q);
    }
    
    
    return 0;
}
#else
#endif


/*.........................................................................................*/






#pragma mark 连通性问题的快速并集解决方案
#ifdef p2
#define N 10
#include <stdio.h>
int main(void) {
    // insert code here...
    int i, p, q, j, id[N];
    for (i = 0; i< N; i++) {
        id[i] = i;
    }
    
    
    while (scanf("%d %d", &p, &q) == 2) {
        
        for(i = p; i != id[i]; i= id[i]);
        for(j = q; j != id[j]; j= id[j]);
        if (i == j)  continue;
        id[i] = j;
        printf("output: %d %d\n", p, q);
    }
    
    
    return 0;
}
#else
#endif



/*.........................................................................................*/






#pragma mark 连通性问题的快速并集加权算法
#ifdef p3
#define N 10
#include <stdio.h>
int main(void) {
    // insert code here...
    int i, p, q, j, id[N], sz[N];
    for (i = 0; i< N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    
    
    while (scanf("%d %d", &p, &q) == 2) {
        
        for(i = p; i != id[i]; i= id[i]);
        for(j = q; j != id[j]; j= id[j]);
        if (i == j)  continue;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        }else{
            id[j] = i;
            sz[i] += sz[j];
        }
        printf("output: %d %d\n", p, q);
    }
    
    
    return 0;
}
#else
#endif



/*.........................................................................................*/








#pragma mark 连通性问题的对分路径压缩
#ifdef p4
#define N 10
#include <stdio.h>
int main(void) {
    // insert code here...
    int i, p, q, j, id[N], sz[N];
    for (i = 0; i< N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    
    
    while (scanf("%d %d", &p, &q) == 2) {
        
        for(i = p; i != id[i]; i= id[i])
            id[i] = id[id[i]];
        
        for(j = q; j != id[j]; j= id[j])
            id[j] = id[id[j]];
        
        if (i == j)  continue;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        }else{
            id[j] = i;
            sz[i] += sz[j];
        }
        printf("output: %d %d\n", p, q);
    }
    
    
    return 0;
}
#else
#endif


/*.........................................................................................*/





#pragma mark 程序2-1 顺序搜索

#ifdef p5

#define N 10
#define M 100

#include <stdio.h>
#include <time.h>

int main(void) {
    // insert code here...
    
    int a[N], b[M], i, l, r;
    for ( i = 0; i< N ; i++) {
        a[i] = rand()%(N+1);
    }
    for (i=0; i<M; i++) {
        b[i] = rand()%(M+1);
    }
    
    for (i = 0; i < M; i++) {
        int j = mysearch(a, b[i], 0, N-1);
        printf("%d\n", j);
    }
    
    return 0;
}

int mysearch(int a[], int v, int l, int r){
    for (int i= l ; i <= r; i++) {
        if (v == a[i]) {
            return i;
        }
    }
    return -1;
}

#else
#endif


/*.........................................................................................*/




#pragma mark 程序2-2 二分搜索
#ifdef p6
#define N 10
#define M 1000

#include <stdio.h>
#include <time.h>

int main(void) {
    // insert code here...
 
    int a[N], b[M], i, l, r;
    for (i = 0; i< N; i++) {
        a[i] = rand()%(N+1);
    }
    
    for (i = 0; i<M; i++) {
        b[i] = rand()%(M+1);
    }
    
    for (i = 0; i< M; i++) {
        int j = mysearch(a, b[i], 0, N-1);
        printf("%d\n", j);
    }
    
    return 0;
}

int mysearch(int a[], int v, int l, int r){
    while (r >= l) {
        int m = (l+r)/2;
        if (v == a[m]) {
            return m;
        }
        
        if (v < a[m]) {
            r = m - 1;
        }else {
            l = m + 1;
        }
    }
    return  -1;
}

#else
#endif


/*.........................................................................................*/






#pragma mark 程序3-9 循环列示例 约瑟夫问题
#ifdef p7

#define N 10
#define M 3

#include <stdio.h>
typedef struct node* link;
struct node {int item; link next;};
int main(void) {
    // insert code here...
    
    int i;
    link t = malloc(sizeof *t), x = t;
    t->item = 1;
    t->next = t;
    for (i = 2; i<= N; i++) {
        x = (x->next = malloc(sizeof *x));
        x->item = i;
        x->next = t;
    }
    
    while (x != x->next) {
        for (i = 1; i < M; i++) {
            x = x ->next;
        }
        x ->next = x->next->next;
    }
    printf("%d\n", x->item);
    
    return 0;
}
#else
#endif


/*.........................................................................................*/








#pragma mark 程序3-10 倒置表
#ifdef p8
#define N 10
#include <stdio.h>



int main(void) {
    // insert code here...

    
    return 0;
}
#else
#endif


/*.........................................................................................*/





#pragma mark 程序3-11 表插入排序
#ifdef p9
#define N 10
#include <stdio.h>

typedef struct node* link;
struct node {int item; link next;};
int main(void) {
    // insert code here...
    struct node heada, headb;
    link t, u, x, a=&heada, b;
    int i ;
    for (i= 0, t=a; i<N; i++) {
        t->next = malloc(sizeof *t);
        t = t->next;
        t ->next = NULL;
        t->item = rand()%1000;
    }
    
    b = &headb;
    b->next = NULL;
    for (t = a->next; t != NULL; t =u) {
        u = t->next;
        for (x = b; x->next != NULL; x = x->next) {
            if (x->next->item > t->item) {
                break;
            }
            t->next = x->next;
            x->next = t;
        }
    }
    
    return 0;
}
#else
#endif


/*.........................................................................................*/







#pragma mark 程序3-13 约瑟夫问题的表分配
#ifdef p10
#define N 10
#include <stdio.h>



int main(void) {
    // insert code here...
    
    
    return 0;
}
#else
#endif


/*.........................................................................................*/






#pragma mark 程序4-1 下推栈的ADT接口
#ifdef p4_1
#define N 10
#include <stdio.h>
int main(void) {
    // insert code here...
    
    
    return 0;
}
#else
#endif


/*.........................................................................................*/





#pragma mark 堆排序
#ifdef HeapSortT
#include <stdio.h>

//array是待调整的堆数组，i是待调整的数组元素的位置，length是数组的长度，i是待调整的数组元素的位置
//函数功能:根据数组array构建大根堆
void heapAdjust(int array[], int i, int length){
    int child = 0;
    int temp = 0;
    for (; 2 * i + 1 < length; i = child) {
        
        //子节点的位置 = 2 * (父节点的位置) + 1
        child = 2 * i + 1;
        
        //右子节点存在的情况下,比较左子节点和右子节点的大小,如果右子节点更大，则child则为右子节点
        //得到较大的子节点
        if (child < length - 1 && array[child+1] > array[child]) {
            ++ child;
        }
        
        //如果较大的子节点大于父节点，那么将较大的子节点和父节点互换
        if (array[i] < array[child]) {
            temp = array[i];
            array[i] = array[child];
            array[child] = temp;
        }
        else break; //否则退出循环
    }
}


//堆排序算法
void heapSort(int array[], int length){
    
    int i = 0;
    
    //调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    // length/2 - 1是最后一个非叶子节点，这是完全二叉树的性质决定
    for (i = length/2 - 1; i>=0; --i) {
        heapAdjust(array, i, length);
    }
    
    
    //对最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for (i = length - 1; i>0; --i) {
        //把第一个元素和当前最后一个元素交换
        //保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
//        array[i] = array[0] ^ array[i];
//        array[0] = array[0] ^ array[i];
//        array[i] = array[0] ^ array[i];
        
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        
        
        //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        heapAdjust(array, 0, i);
    }
}


int main() {
    // insert code here...
    int i;
    int num[] = {9,8,7,6,5,4,3,2,1,0};
    heapSort(num, sizeof(num)/sizeof(int));
    for (i = 0; i< sizeof(num)/sizeof(int); i++) {
        printf("%d ", num[i]);
    }
    printf("\nok\n");
    return 0;
}
#else
#endif


/*.........................................................................................*/





#pragma mark 归并排序
#ifdef MergeSortT
#define N 10
#include <stdio.h>
#include <stdlib.h>
//合并有序队列
void Merge(int sourceArr[], int tempArr[], int startIndex, int middleIndex, int endIndex){
    int i = startIndex, j = middleIndex + 1, k = startIndex;
    while (i != middleIndex + 1 && j != endIndex + 1) {
        if (sourceArr[i] > sourceArr[j]) {
            tempArr[k++] = sourceArr[i++];
        }else{
            tempArr[k++] = sourceArr[j++];
        }
    }
    
    while (i != middleIndex + 1) {
        tempArr[k++] = sourceArr[i++];
    }
    
    while (j != endIndex + 1) {
        tempArr[k++] = sourceArr[j++];
    }
    
    for (i = startIndex; i<=endIndex; i++) {
        sourceArr[i] = tempArr[i];
    }
}

//内部使用了递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex){
    int midIndex;
    if (startIndex < endIndex) {
        midIndex = (startIndex + endIndex) / 2;
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

int main(void) {
    // insert code here...
    
    int  a[10] = {50, 45, 69, 32, 12, 71, 22, 14, 5, 4};
    int i , b[10];
    MergeSort(a, b, 0, 9);
    for (i = 0; i< 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\nok");
    
    return 0;
}
#else
#endif


/*.........................................................................................*/





#pragma mark 计数排序
#ifdef CountingSortT


#include <stdio.h>
#include <stdlib.h>
#define random(x) rand()%(x)
#define NUM 100    //产生100个随机数
#define MAXNUM 200  //带排序的数字范围是0-200

void countingSort(int A[], int n, int k){
    int *ptemp, *pout;
    int i;
    ptemp = (int *)malloc(sizeof(int) *k);
    pout = (int *)malloc(sizeof(int) *n);
    
    for (i =0; i<k; i++) {
        ptemp[i] = 0;
    }
    
    for (i =0 ; i<n; i++) {
        ptemp[A[i]] += 1;
    }
    
    for (i = 1; i<k; i++) {
        ptemp[i] = ptemp[i-1] + ptemp[i];
    }
    
    for (i = n -1; i >= 0; i--) {
        pout[ptemp[A[i]] - 1] = A[i];  // ptemp[A[i]] - 1 代表小于等于A[i]的元素个数，就是A[i]在B中的位置
        ptemp[A[i]] -= 1;
    }
    
    for (i = 0; i< n; i++) {
        A[i] = pout[i];
    }
    
    free(ptemp);
    free(pout);
}

void printArray(int A[], int n){
    
    int i = 0;
    for (i = 0; i< n; i++) {
        printf("%4d", A[i]);
    }
    printf("\n");
}


int main(void) {
    // insert code here...
    int A[NUM];
    int i;
    for (i = 0; i< NUM; i++) {
        A[i] = random(MAXNUM);
    }
    
    printf("before sorting:\n");
    printArray(A, NUM);
    countingSort(A, NUM, MAXNUM);
    printf("after sorting:\n");
    printArray(A, NUM);
    
    return 0;
}
#else
#endif


/*.........................................................................................*/











#pragma mark 基数排序
#ifdef RadixSortT
#define N 10
#include <stdio.h>
int main(void) {
    // insert code here...
    
    
    return 0;
}
#else
#endif


/*.........................................................................................*/














#pragma mark 快速排序

#ifdef QuickSortT

#include <stdio.h>
#include <stdlib.h>
#define random(x) rand()%(x)
#define NUM 100    //产生100个随机数
#define MAXNUM 200  //带排序的数字范围是0-200


void quickSort(int *a, int left, int right){
    
    //如果左边索引大于或者等于右边索引说明已经整理完成了一个组
    if (left >= right) {
        return;
    }
    
    int i = left;
    int j = right;
    int key = a[left];
    
    while (i < j) {
        
        while (i < j && key <= a[j]) {
            j--;
        }
        
        a[i] = a[j];
        
        while (i < j && key > a[i]) {
            i++;
        }
        
        
        a[j] = a[i];
    }
    
    a[i] = key;
    
    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}


void printArray(int A[], int n){
    
    int i = 0;
    for (i = 0; i< n; i++) {
        printf("%4d", A[i]);
    }
    printf("\n");
}


int main(void) {
    // insert code here...
    int A[NUM];
    int i;
    for (i = 0; i< NUM; i++) {
        A[i] = random(MAXNUM);
    }
    
    printf("before sorting:\n");
    printArray(A, NUM);
    quickSort(A, 0, NUM -1);
    printf("after sorting:\n");
    printArray(A, NUM);
    
    return 0;
}
#else
#endif


/*.........................................................................................*/







#pragma mark 希尔排序
#ifdef SheelSortT

#include <stdio.h>
#include <stdlib.h>

#define random(x) rand()%(x)
#define NUM 10    //产生100个随机数
#define MAXNUM 20  //带排序的数字范围是0-200

void shellSort(int *a, int n){
    
    int  j=0, gap=0;
    
    for (gap = n/2; gap > 0; gap/=2) {   //步长
        
        //数组中的第gap个元素开始，其实是从每一个分组中的第二个元素开始，插入排序就是这么做的
        for (j = gap; j < n; j++) {
            
            //和同组中前一个元素进行比较
            if (a[j] < a[j - gap]) {
                
                int temp = a[j];
                int k = j - gap;
                while (k >= 0 && a[k] > temp) {
                    a[k + gap] = a[k];
                    k -= gap;
                }
                a[k + gap] = temp;
            }
            
        }
    }
}


void printArray(int A[], int n){
    
    int i = 0;
    for (i = 0; i< n; i++) {
        printf("%4d", A[i]);
    }
    printf("\n");
}


int main(void) {
    // insert code here...
    
    int A[NUM];
    int i;
    for (i = 0; i< NUM; i++) {
        A[i] = random(MAXNUM);
    }
    
    printf("before sorting:\n");
    printArray(A, NUM);
    shellSort(A, NUM);
    printf("after sorting:\n");
    printArray(A, NUM);
    return 0;
}
#else
#endif


/*.........................................................................................*/




#pragma mark 模板
#ifdef test

#include <stdio.h>
int main(void) {
    // insert code here...
    
    
    return 0;
}
#else
#endif


/*.........................................................................................*/
