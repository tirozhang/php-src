#include<stdio.h>
#include"../../Zend/zend.h"

int main(){
    zval *test = "abc";
    printf("这个变量的数据类型不是NULL，这种数据类型对应的数字是： %d", test->type);
    return 0;
    
}
