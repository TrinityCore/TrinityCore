#include <stdio.h>
#include <string.h>
int main()
        {  FILE* file = fopen_s("a.txt", "r");
           char buff[1000];
           char new_buff[1000];
           int i = 0;  /* һ��һ�ж� */
           while(fgets(buff, 1000, file) != NULL)
                    { //  printf("%s\n", buff);
                        char a[100];   int b, c;   /* ȫ�����������ڱ������� */
                        sscanf_s(buff, "%s %d %d\n", a, &b, &c);
                        //  printf("a = %s, b = %d, c = %d\n", a, b, c);    /* ���������ģ� ���磺�Ƚ����֣������xiaozhu��ô�Ѻ����100�ĳ�50 */
                        if(strcmp(a, "xiaozhu") == 0)   {    c = 50;   }   /* end ���� */      /* ����һ���µ�Ҫд���ļ���char* */
                        sprintf_s(new_buff+i, "%s %d %d\n", a, b, c);
                        i = strlen(new_buff);  }
                        fclose(file);
                        // printf("new buff is %s\n", new_buff);    /* д���ļ� */
                        FILE* file2 = fopen_s("a.txt", "w");
                        fwrite(new_buff, sizeof(char), strlen(new_buff), file2);
                        fclose(file2);
                        return 0; 
                        }