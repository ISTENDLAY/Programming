#include <math.h>

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