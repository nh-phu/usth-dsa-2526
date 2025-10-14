#include <stdio.h>
#include <stdlib.h>

struct website {
    char *title;
    char *url;
    struct website *pNext;
};

struct stack {
    int size;
    struct website *pTop;
};

struct stack backward;
struct stack forward;

void initStack(struct stack *st)
{
    st->size = 0;
    st->pTop = NULL;
}

void initWebsite(char *newtitle, char *newurl)
{
    struct website *p;
    p = (struct website *)malloc(sizeof(struct website));
    if(p == NULL)
        return;
    p->title = newtitle;
    p->url = newurl;
    p->pNext = NULL;
}

int checkEmpty(struct stack st)
{
    return (st.size == 0);
}

int push(struct stack *st, struct website *new)
{
    new->pNext = st->pTop;
    st->pTop = new;
    st->size++;
    return 1;
}

int pop(struct stack *st)
{
    struct website *p;
    struct stack *other = (st == &backward)? &forward : &backward;
    if(checkEmpty(*st))
        return 0;
    p = st->pTop;
    st->pTop = p->pNext;
    st->size--;

    push(other, p);
    return 1;
}

void display(struct stack st) {
    struct website *curr = st.pTop;
    for(int i = 1; i <= st.size; i++) {
        printf("Title: %s\n", curr->title);
        printf("Url: %s\n", curr->url);
        printf("------------------------");
    }
    printf("\n");
}

int main() {
    initStack(&backward);
    initStack(&forward);
    return 0;
}
