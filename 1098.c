#include<stdio.h>
#include<stdlib.h>

typedef struct listNode {
    int data;
    struct listNode *next;
} listNode, linkList;

/* 插入结点 */
void linkListInsert(linkList *L, int i, int data)
{
    int count;
    listNode *p = L;

    count = 0;
    while (count < i - 1) {
        p = p->next;
        count++;
    }

    listNode *q = (listNode *)malloc(sizeof(listNode));
    q->data = data;
    q->next = p->next;
    p->next = q;
}

/* 删除结点 */
void linkListDelete(linkList *L, int i)
{
    listNode *p = L;
    while (i > 1) {
        p = p->next;
        i--;
    }
  
    listNode *q = p->next;
    p->next = q->next;
    q->next = NULL;
    if (q != NULL) {
        free(q);
    }
}

/* 获得链表长度 */
int getLinkListLength(linkList *L)
{
    listNode *p = L;
    int count;

    count = 0;
    while (p->next != NULL) {
        p = p->next;
        count++;
    }

    return count; 
}

/* 输出链表 */
void printfLinkList(linkList *L)
{
    listNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        printf("%d ", p->data);
    }

    printf("\n");
}

int main()
{
    int x, y;
    int now;
    int i, j;
    scanf("%d", &x);
    scanf("%d", &y);
  
    linkList *L = (linkList *)malloc(sizeof(linkList));
    L->next = NULL;
    /* 初始化链表，为每个小朋友编号 */
    for (i = 0, j = 1; i < x; i++, j++) {
        linkListInsert(L, j, i);
    }

    now = 1;
    while (getLinkListLength(L) > 1) {
        /* 得到当前要删除的小朋友编号 */
        now = (now + y - 1) % getLinkListLength(L);
        if (now == 0) {
            now = getLinkListLength(L);
        }

        /* 删除小朋友 */
        linkListDelete(L, now);
    }

    /* 输出最后留下的小朋友编号 */
    printfLinkList(L);
    return 0;
}
