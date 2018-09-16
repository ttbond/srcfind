//
// Created by ttbond on 18-9-15.
//
#include<stdio.h>
class abc{
public:
    abc(){}
    static int a;
};


int main(){
    abc a;
    a.a=100;
    printf("%d\n",a.a);
}
