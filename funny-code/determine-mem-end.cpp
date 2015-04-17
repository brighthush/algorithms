// 判断内存的大小端
// 大端 ： 数据的低位存在高地址
// 小端 ： 数据的低位存在低地址

#include <iostream>
#include <cstdio>

union Node
{
    char ch;
    int val;
};

int main()
{
    // use union to determine the end problem
    Node node;
    node.val = 0;
    node.ch = 1;
    if(node.val == 1) { printf("little end. \n"); }
    else { printf("big end.\n"); }

    //another method
    printf("%d\n", sizeof(short));
    short a = 0x1234;
    char b = *(char *)&a;
    if(b==0x12) { printf("big end\n"); }
    else if(b==0x34) { printf("little end\n"); }
    return 0;
}
