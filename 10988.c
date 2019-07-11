#include<stdio.h>
#include<stdlib.h>

typedef struct listNode {
  int data;
  struct listNode *next;
} listNode, linkList;

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

  /*  */
  for (i = 0, j = 1; i < x; i++, j++) {
    linkListInsert(L, i, j);
  }

  now = 1;
  while (getLinkListLength(L) > 1) {
    now = (now + y - 1) % getLinkListLength(L);
    if (now == 0) {
      now = getLinkListLength(L);
    }
    linkListDelete(L, now);
  }

  printfLinkList(L);
  printf("%d\n", getLinkListLength(L));
  return 0;
}
