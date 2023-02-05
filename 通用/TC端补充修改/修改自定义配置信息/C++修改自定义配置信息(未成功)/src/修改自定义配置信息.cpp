#include <stdio.h>
#include <string.h>
int main()
        {  FILE* file = fopen_s("a.txt", "r");
           char buff[1000];
           char new_buff[1000];
           int i = 0;  /* 一行一行读 */
           while(fgets(buff, 1000, file) != NULL)
                    { //  printf("%s\n", buff);
                        char a[100];   int b, c;   /* 全部读出来存在变量里面 */
                        sscanf_s(buff, "%s %d %d\n", a, &b, &c);
                        //  printf("a = %s, b = %d, c = %d\n", a, b, c);    /* 这里做更改， 比如：比较名字，如果是xiaozhu那么把后面的100改成50 */
                        if(strcmp(a, "xiaozhu") == 0)   {    c = 50;   }   /* end 更改 */      /* 构造一个新的要写入文件的char* */
                        sprintf_s(new_buff+i, "%s %d %d\n", a, b, c);
                        i = strlen(new_buff);  }
                        fclose(file);
                        // printf("new buff is %s\n", new_buff);    /* 写入文件 */
                        FILE* file2 = fopen_s("a.txt", "w");
                        fwrite(new_buff, sizeof(char), strlen(new_buff), file2);
                        fclose(file2);
                        return 0; 
                        }