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
#define p4_1 //程序4-1 下推栈的ADT接口




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





#pragma mark 模板
#ifdef test
#define N 10
#include <stdio.h>
int main(void) {
    // insert code here...
    
    
    return 0;
}
#else
#endif


/*.........................................................................................*/





#pragma mark 模板
#ifdef test
#define N 10
#include <stdio.h>
int main(void) {
    // insert code here...
    
    
    return 0;
}
#else
#endif


/*.........................................................................................*/





#pragma mark 模板
#ifdef test
#define N 10
#include <stdio.h>
int main(void) {
    // insert code here...
    
    
    return 0;
}
#else
#endif


/*.........................................................................................*/
