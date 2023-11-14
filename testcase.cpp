#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int original_price;
int discounted_price;

int main(){
    int i;
    printf("输入折扣方式:");
    while(scanf("%d",i)){
        switch(i){
            case 1:
            discounted_price = original_price;
            case 2:
            discounted_price = original_price*0.9;
            case 3:
            discounted_price = original_price-original_price % 100 * 30;
        } 
    }
}