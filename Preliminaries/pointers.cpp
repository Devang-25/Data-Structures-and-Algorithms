#include<iostream>
using namespace std;

int max(int x, int y){
    return x>y?x:y;
}
int min(int x, int y){
    return x>y?y:x;
}

int main(){


    int a = 10;
    int *p; // Declaring a pointer
    p = &a; // Initializing pointer

    cout<<a<<endl;
    cout<<p<<endl;
    cout<<&a<<endl;
    cout<<*p<<endl; // Dereferencing pointer

    // Heap memory allocation and Dynamic Memory Allocation
    int *q = new int[5];
    q[2]= 23;

    delete []p;

    q = new int[10];


    delete []q;
    q = nullptr;
    cout<<"-----------------"<<endl;
    // Pointer arithmetic
    int array[5]={3,2,4,9,20};
    int *r=array, *s=&array[3];

    cout<<*r<<" "<<*s<<endl;
    r++; s--;
    cout<<*r<<" "<<*s<<endl;
    r--; s++;
    cout<<s-r<<" hello"<<endl;
    for(int j=0;j<5;j++){
        cout<<array[j]<<" "<<j[array]<<endl;
        cout<<*(array+j)<<" "<<*(j+array)<<endl;
        cout<<array+j<<endl;
    }

    int (*fp)(int, int) = max;
    cout<<(*fp)(10,5)<<endl;
//    int (*fp)(int, int) = min;
    fp = min;
    cout<<(*fp)(10,5)<<endl;



return 0;
}
