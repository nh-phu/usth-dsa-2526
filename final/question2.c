#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int frequency;
} Element;

typedef struct {
    int size;
    Element data[100];
} List;

List *initList()
{
    List *init = (List *)malloc(sizeof(List));
    init->size = 0;
    return init;
}

void add(List *I, int value)
{
    if (I->size == 0) {
        Element *initElement = (Element *)malloc(sizeof(Element));
        initElement->value = value;
        initElement->frequency = 1;
        I->data[I->size] = *initElement;
        I->size++;
    } else {
        int check = 0;
        for (int i = 0; i < I->size; i++) {
            if (I->data[i].value == value) {
                I->data[i].frequency++;
                check++;
                break;
            }
        }
        if (check == 0) {
            Element *initElement = (Element *)malloc(sizeof(Element));
            initElement->value = value;
            initElement->frequency = 1;
            I->data[I->size] = *initElement;
            I->size++;
        }
    }
}

void display(List I)
{
    printf("This list has size:%d\n", I.size);
    for (int i = 0; i < I.size; i++) {
        printf("Value: %d | Frequency: %d\n", I.data[i].value, I.data[i].frequency);
    }
}

int main() {
    List *I = initList();
    add(I, 5);
    add(I, 3);
    add(I, 5);
    add(I, 2);
    add(I, 3);
    add(I, 3);
    add(I, 5);
    add(I, 4);
    add(I, 1);
    add(I, 1);

    display(*I);
    free(I);
    return 0;
}
