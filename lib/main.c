#include <stdio.h>

int isPrimary(int num);

int main(){
    int a;
    do{
        printf("type a non-negative number: ");
        scanf("%d", &a);
    }
    while (a<0);
    if (isPrimary(a)==1){
        printf("is primary");
    }
    else{
        printf("isn't primary");
    }
    return 0;
}