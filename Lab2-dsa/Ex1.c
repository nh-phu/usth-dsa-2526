#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int *digits;
    int size;
} num;

void init(num* I) {
    I->digits = (int*)calloc(200,sizeof(int));
    I->size = 0;
}

int isEmpty(num* I) {
    return (I->size ==0);
}

void add(num* I,int new) {
    if(isEmpty(I)) {
        if(new == 1 || new == -1) {
            I->digits[I->size] = new;
            I->size++;
        } else {
            printf("Must declare sign.");
        } 
    }
    else {
        I->digits[I->size] = new;
        I->size++;
    }
}
void rem(num* I, int pos) {
    if (I->size ==0) {
        printf("Invalid");
    };
    I->digits[pos] = 0;
    I->size--;
    /* if(pos == I->size){
        while(I->digits[pos] == 0) {
            pos -= 1;
            I->size -=1;
        }
    } */
}

int cal(num I) {
    int res = 0;
    for(int i = I.size; i >= 1; i--) {
        res += I.digits[i];
    }
    return res;
}

void display(num I) {
    printf("%c", (I.digits[0] == 1)? '+':'-');
    for(int i = 1; i <= I.size; i++) {
        printf("%d",I.digits[i]);
    }
    printf("\n");
}

int main() {
    num f;
    init(&f);
    add(&f, -1);
    add(&f, 2);
    add(&f, 7);
    add(&f, 9);
    display(f);
    printf("%d\n", cal(f));
    free(f.digits);
    return 0;
}
