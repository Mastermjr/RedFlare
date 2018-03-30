//
// Created by Spencer Kline on 3/29/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void memdmp(FILE *fd, char * p , int len)
{
    int i, c, count = 0, sec = 16, leftovers = 0;
    int loop = 16;
    while ( count <= len)
    {
        if ( count / 16 == len / 16)
        {
            if (len % 16 == 0)
            {
            break;
            }
            else {
                loop = len % 16;
            }
        }
        printf("0x%016lx: ", (unsigned long) p +count);
        for (i = count; i <count + loop; i++)
        {
            c = p[i]&0xff;
            printf("%02X ", c );
        }

        for ( i = 0; i < 16 - loop; i++)
        {
            printf(" ");
        }
        printf(" ");
        for ( i = count; i < len && i < count + 16; i++)
        {
            c = p[i]&0xFF;
            printf("%c", (128>c&&c>=32)?c:'.');
        }
        count += 16;
        printf("\n");
    }
}

struct X{
    char a;
    int i;
    char b;
    int *p;
};

struct List {
    char * str;
    struct List * next;
};

int
main() {
    char str[20];
    int a = 5;
    int b = -5;
    double y = 12;
    struct X x;
    struct List * head;

    x.a = 'A';
    x.i = 9;
    x.b = '0';
    x.p = &x.i;
    strcpy(str, "Hello world\n");
    printf("&str=0x%lX\n", (unsigned long)str);
    printf("&a=0x%lX\n", (unsigned long)&a);
    printf("&b=0x%lX\n", (unsigned long)&b);
    printf("&x=0x%lX\n", (unsigned long)&x.a);
    printf("&y=0x%lX\n", (unsigned long) &y);

    memdmp(stdout, (char *) &x.a, 64);
    head = (struct List *) malloc(sizeof(struct List));
    head->str=strdup("Welcome ");
    head->next = (struct List *) malloc(sizeof(struct List));
    head->next->str = strdup("to ");
    head->next->next = (struct List *) malloc(sizeof(struct List));
    head->next->next->str = strdup("cs250");
    head->next->next->next = NULL;
    printf("head=0x%lx\n", (unsigned long) head);
    memdmp(stdout, (char*) head, 128);
}