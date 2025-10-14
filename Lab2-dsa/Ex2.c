#include <stdio.h>
#include <stdlib.h>

struct car {
    int pass;
    char *id;
    struct car *pNext;
};

struct train {
    int size;
    struct car *pHead;
    struct car *pTail;
};

void initTrain(struct train *I)
{
    I->size = 0;
    I->pHead = NULL;
    I->pTail = NULL;
}

struct car *initCar(int pass, char *name)
{
    struct car *car = (struct car *)malloc(sizeof(*car));
    car->pass = pass;
    car->id = name;
    car->pNext = NULL;
    return car;
}

int checkemptytrain(struct train *I)
{
    return (I->size == 0);
}

void add(struct train *I, struct car *newcar)
{
    if (checkemptytrain(I)) {
        I->size++;
        I->pHead = newcar;
        I->pTail = newcar;
    }   else {
        I->size++;
        I->pTail->pNext = newcar;
        I->pTail = newcar;
    }
}

void checkemptycar(struct train *I) {
    if (checkemptytrain(I))
        printf("There's no car\n");
    else {
        struct car *curr = I->pHead;
        struct car *prev = NULL;
        while (curr != NULL) {
            if (curr->pass == 0) {
                if(prev == NULL) {
                    I->pHead = curr->pNext;
                    if(I->pHead ==NULL) {
                        I->pTail = NULL;
                    }
                    free(curr);
                    curr = I->pHead;
                } else {
                    prev->pNext = curr->pNext;
                    if(curr == I->pTail) {
                        I->pTail = prev;
                    }
                    free(curr);
                    curr = prev->pNext;
                }
                I->size--;
            } else {
                prev = curr;
                curr = curr->pNext;
            }
        }
    }
}

void printinfo(struct train *I) {
    struct car *temp = I->pHead;
    while(temp != NULL) {
        printf("Car name: %s | Number of passengers: %d\n", temp->id, temp->pass);
        temp = temp->pNext;
    }
    printf("Number of car: %d\n", I->size);
}

int main() {
    struct train Train;
    initTrain(&Train);
    struct car *Car1 = initCar(0,"A");
    struct car *Car2 = initCar(10,"B");
    struct car *Car3 = initCar(0,"C");
    struct car *Car4 = initCar(8,"D");
    add(&Train,Car1);
    add(&Train,Car2);
    add(&Train,Car3);
    add(&Train,Car4);
    checkemptycar(&Train);
    printinfo(&Train);

    struct car *curr = Train.pHead;
    while (curr != NULL) {
        struct car *next = curr->pNext;
        free(curr);
        curr = next;
    }

    return 0;
}
