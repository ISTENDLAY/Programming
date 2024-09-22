#include <stdio.h>
#include <math.h>

int isPrimary(int num);
double sqrt(double x);

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

int isPrimary(int num){
    if (num<2){
        return 0;
    }
    for (int i = 2; i <= sqrt((num)); i++){
        if (num%i==0){
            return 0;
        } 
    }
    return 1;
}