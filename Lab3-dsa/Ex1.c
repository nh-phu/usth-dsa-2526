#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char *item;
    int quantity;
};

struct customer {
    char *item;
    int quantity;
    struct customer *pNext;
};

struct customer *initCustomer(char *item, int qua)
{
    struct customer *p = (struct customer *)malloc(sizeof(struct customer));
    p->item = item;
    p->quantity= qua;
    return p;
}

const int N = 10;

struct queue {
    int inl;
    struct customer *pHead;
    struct customer *pTail;
};

void initQueue(struct queue *q)
{
    q->inl = 0;
    q->pHead = NULL;
    q->pTail = NULL;
};

void en(struct queue *q, struct customer *cus)
{
    if(q->inl == N)
        printf("Full!");
    else {
        if(q->inl == 0) {
            q->pHead = cus;
            q->pTail = cus;
        } else {
            q->pTail->pNext = cus;
            q->pTail = cus;
        }
        q->inl += 1;
    }
};

void de(struct queue *q, struct product *l)
{
    if(q->inl == 0)
        printf("No one in the queue");
    else {
        int i = 0;
        struct customer *buying = q->pHead;
        while(!strcmp(l[i].item,buying->item)) {
            i++;
        }
        if(l[i].quantity == 0) {
            printf("Out of stock.");
            return;
        } else {
            l[i].quantity -= buying->quantity;
        }
        if(buying == q->pHead) {
            q->pHead = NULL;
            q->pTail = NULL;
        } else {
            q->pHead = buying->pNext;
        }
        q->inl--;
        free(buying);
    }
};

void initProd(struct product *Pro, char *item, int quan)
{
    Pro->item = item;
    Pro->quantity = quan;
}

int main() {
    struct product *list = (struct product *)malloc(3*sizeof(struct product));
    struct queue *q = (struct queue *)malloc(N*sizeof(struct queue));
    initProd(&list[0], "milk", 5);
    initProd(&list[1], "apple", 7);
    initProd(&list[2], "egg", 4);
    free(list);
    free(q);
    return 0;
}
