#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* ��ʽ��puts(�ַ�������)
* ���ܣ����ַ������е��ַ����������ʾ����������Ļ����ʾ���ַ�����
*/
void puts_function()
{
    char str[] = "DO MORE \nSAY LESS";
    puts(str);
}

/**
* ��ʽ��gets���ַ���������
* ���ܣ��ӱ�׼�����豸������һ���ַ���
* �������õ�һ������ֵ�� ��Ϊ���ַ�������׵�ַ
*/
void gets_function()
{
    char str[22];
    printf("input string's length less than 21:\n");
    gets(str);
    puts(str);
}


/**
* ��ʽ��strcat(dest������, src������)
* ���ܣ���src�ַ������е��ַ������ӵ�dest�ַ������ַ����ĺ��棬 ��ɾȥdest�ַ�����Ĵ���־"\0".
* ����������ֵ��dest�ַ������׵�ַ��
*/
void strcat_function()
{
    static char str[50] = "Always tell a good story.";
    char str2[10];    // WC, here is int
    printf("Input your name:\n");
    gets(str2);
    strcat(str, str2);
    puts(str);
}

/**
* ��ʽ��strcpy(dest, src)
* ���ܣ���src�ַ������е��ַ���������dest�ַ������С� ��������־'\0'Ҳһͬ������src�ַ���Ҳ������һ��"�ַ���"
* ��ʱ�൱�ڰ�һ���ַ�������һ���ַ�����
*/
void strcpy_function()
{
    char str[20], str2[] = "Learn C Language again!";
    strcpy(str, str2);
    puts(str);
    printf("\n");
}

/**
* ��ʽ��strncpy(dest, src, n)
* ����: �� src ����� n ���ַ����ƽ� dest �ַ�����
*
*/
void strncpy_function()
{
    char str[20];
    char str2[] = "I made a fault!";
    strncpy(str, str2, 15);
    puts(str);
}

/**
* ��ʽ��strlen(�ַ�������)
* ���ܣ����ַ�����ʵ�ʳ��ȣ������ַ���������־ '\0'������Ϊ��������ֵ��
*/

void strlen_function()
{
    static char str[] = "Learn C language again!";
    int len = strlen(str);
    printf("the str length: %d\n", len);
}

/**
* ��ʽ��char* strchr(str, c)
* ���ܣ�str ΪҪ���ҵ��ַ����� c ΪҪ���ҵ��ַ��� Ȼ�󽫸õ�ַ����
*/
void strchr_function()
{
    char *str = "123456789068899567766";
    char *p;
    p = strchr(str, '5');
    printf("%s\n", str);
    printf("%s\n", p);
}


/**
* ��ʽ��int atoi(const char* str)
* ���ܣ�atoi()��ɨ����� str �ַ����� ����ǰ��Ŀհ��ַ���ֱ���������ֻ������Ųſ�ʼ��ת����
*       �������������ֻ��ַ�������ʱ('\0')�Ž���ת��������������ء�
* ����ֵ�� ����ת����������ͣ���� str ����ת���� int ���� str Ϊ���ַ�������ô���� 0
*/
void atoi_functon()
{
    char buffer[256];
    printf("Enter a number:");
    fgets(buffer, 256, stdin);
    printf("The value entered is %d\n", atoi(buffer));
}

int main()
{
    puts_function();
    gets_function();
    strcat_function();
    strcpy_function();
    strlen_function();
    strncpy_function();
    strchr_function();
    atoi_functon();
    return 0;
}
