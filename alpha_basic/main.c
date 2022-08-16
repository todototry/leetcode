#include <stdlib.h>  
#include <stdio.h>
#include <signal.h>
 
// 回调函数
void populate_array(int *array, size_t arraySize, int (*getNextValue) (void))
{
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue();
}
 
// 获取随机值
int getNextRandomValue(void)
{
    return rand();
}

void handler(int sig) {
  printf("Handler called for signal %d\n", sig);
}

int main(void)
{
    //signal(SIGINT, SIG_DFL);
        signal(SIGINT, SIG_IGN);
    //signal(SIGINT, handler);
    raise(SIGINT);

    int myarray[10];
    /* getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针*/
    populate_array(myarray, 10, getNextRandomValue);
    for(int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");

    return 0;
}