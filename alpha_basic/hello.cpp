
#include<iostream>

using namespace std;

typedef int (*fun_ptr)(int,int); // 声明一个指向同样参数、返回值的函数指针类型

int max(int x, int y)
{
    return x > y ? x : y;
}

int main(int argc, char **argv){

    fun_ptr p = max;

    cout << p(1,2) << endl;

    printf("args count: %d", argc);
    return 1;
}
