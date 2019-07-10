#include<stdio.h>
#include<stdlib.h>

/* 定义链表结构体 */
typedef struct listNode {
  int data;
  struct listNode *next;
} linkList;

/* 求链表长度 */
int linkListLength(linkList *L)
{
  int count;
  linkList *p = L;
  
  count = 0;
  while (p->next != NULL) {
      p = p->next;
      count++;
    } 
  
  return count;
}

/* 插入结点 */
void linkListInsert(linkList *L, int i, int e)
{
  linkList *p = L;
  int count;
  
  count = 0;
  while (count < i - 1) {
      p = p->next;
      count++;
    }
  
  listNode *q = (listNode*)malloc(sizeof(listNode));
  q->data = e;
  q->next = p->next;
  p->next = q;
}

/* 删除结点 */
void linkListDelete(linkList *L,int i)
{
  linkList *p = L;
  int count;
  
  count = 0;
  while (count < i-1) {
      p = p->next;
      count++;
    }
  
  listNode *q = p->next;
  p->next = q->next;
  free(q);
}

int main()
{
  int X, Y;
  scanf("%d", &X);
  scanf("%d", &Y);
  linkList L;
  L.next = NULL;
  
  /* 给每个小朋友编号 */
  for (int i = 0, j = 1; i < X && j <= X; i++, j++) {
      linkListInsert(&L, j, i); 
    }
  
  int now = 1;
  while (linkListLength(&L) != 1) {
      /* 得到需要删除的小朋友的编号 */
      now = (now + Y -1 ) % linkListLength(&L);
      if (now == 0) {
            now = linkListLength(&L);
          }
      /* 删除报出Y-1的小朋友 */
      linkListDelete(&L, now);
    } 
  
  /* 输出最后留下来的小朋友编号 */
  listNode *p = L.next;
  printf("%d", p->data);
  return 0;
}
