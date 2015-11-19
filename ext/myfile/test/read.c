#include<stdio.h>
 
int main(void)
{
    FILE *fp = NULL;
    char tmp[100];
    int res = 0;
 
    fp = fopen("test.txt", "r");
    if (NULL == fp)
    {
        printf("file open Fail!\n");
        return -1;
    }
    while(res == 0){
        res = feof(fp);
        printf("%d\n", res);
        if(res != 0){
            break;
        }
        printf("a\n");
        fread(tmp, 1, 100, fp);
//        printf("%s\n", tmp);
    }
 
    fclose(fp);
    fp = NULL;
 
    return 0;
} 
