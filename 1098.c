#include<stdio.h>
#include<stdlib.h>

/* 定义链表结构体 */
typedef struct listNode {
  int data;
  struct listNode *next;
} listNode,  linkList;

/* 求链表长度 */
int linkListLength(linkList *L)
{
  int count;
  listNode *p = L->next;
  
  count = 0;
  while (p != NULL) {
      p = p->next;
      count++;
    } 
  
  return count;
}

/* 插入结点 */
void linkListInsert(linkList *L, int i, int e)
{
  listNode *p = L;
  int count;
  
  count = 0;
  while (count < i - 1) {
      p = p->next;
      count++;
    }
  
  listNode *q = (listNode *)malloc(sizeof(listNode));
  q->data = e;
  q->next = p->next;
  p->next = q;
}

/* 删除结点 */
void linkListDelete(linkList *L,int i)
{
  listNode *p = L;
  int count;
  
  count = 0;
  while (count < i - 1) {
      p = p->next;
      count++;
    }
  
  listNode *q = p->next;
  p->next = q->next;
  if (q != NULL) {
      free(q);
    }
}

int main()
{
  int x, y;
  scanf("%d", &x);
  scanf("%d", &y);
  linkList *L=(linkList *)malloc(sizeof(linkList));;
  L->next = NULL;
  
  /* 给每个小朋友编号 */
  int i, j;
  for (i = 0, j = 1; i < x && j <= x; i++, j++) {
      linkListInsert(L, j, i);  
    }
  
  int now = 1;
  while (linkListLength(L) != 1) {
      /* 得到需要删除的小朋友的编号 */
      now = (now + y -1 ) % linkListLength(L);
      if (now == 0) {
            now = linkListLength(L);
          }
      /* 删除报出y-1的小朋友 */
      linkListDelete(L, now);
    } 
  
  /* 输出最后留下来的小朋友编号 */
  linkList *p = L->next;
  printf("%d", p->data);
  return 0;
}
