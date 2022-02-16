#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *str_replace(char *orig, char *rep, char *with) {
    char *result, *ins, *tmp;
    int len_rep, len_with, len_front, count;

    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL;
        if (!with) with = "";
        len_with = strlen(with);
        ins = orig;
        for (count = 0; tmp = strstr(ins, rep); ++count) {
            ins = tmp + len_rep;
        }
        tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);
        if (!result)
            return NULL;
        while (count--) {
            ins = strstr(orig, rep);
            len_front = ins - orig;
            tmp = strncpy(tmp, orig, len_front) + len_front;
            tmp = strcpy(tmp, with) + len_with;
            orig += len_front + len_rep;
        }
        strcpy(tmp, orig);
        return result;
}

int main() {
    printf("1 - replace a to b\n");
    printf("2 - replace Name to Name1, Name1 to Name\n");
    printf("3 - replace pairs\n");
    printf("4 - count words with 'a'\n");
    printf("5 - format file 'a'\n");

    int n;
    scanf("%d", &n);
    switch (n) {
        case 1: {
            char buf[255];
            scanf("%s", buf);
            char *ptr = buf;
            ptr = str_replace(ptr, "a", "b");
            ptr = str_replace(ptr, "A", "B");
            printf("%s", ptr);
        }
        case 2: {
            char buf[255];
            gets(buf);
            gets(buf);
            char *ptr = buf;
            ptr = str_replace(ptr, "Name1", "N$N");
            ptr = str_replace(ptr, "Name", "Name1");
            ptr = str_replace(ptr, "N$N", "Name");
            printf("%s", ptr);
        }
        case 3: {
            char buf[255];
            gets(buf);
            gets(buf);
            char *ptr = buf;
            for(int i = 1; i < strlen(ptr); i += 2) {
                char p = buf[i];
                buf[i] = buf[i - 1];
                buf[i - 1] = p;
            }
            printf("%s", ptr);
        }
        case 4: {
            char buf[255];
            gets(buf);
            gets(buf);
            char *ptr = buf;
            strcat(ptr, " ");
            int count = 0;
            for (int i = 0; i <= strlen(ptr); ++i) {
                if(buf[i] == 'a' && buf[i + 1] == ' ') count++;
            }
            printf("Amount of words %d", count);
        }
        case 5: {
            char buf[255];
            gets(buf);
            gets(buf);
            char *ptr = buf;
            int count = -1;
            for(int i = strlen(ptr) - 1; i >= 0; i--) {
                if(buf[i] == '.') {
                    count = i;
                    break;
                }
                if(!isalpha(buf[i])) {
                    break;
                }
            }
            if(count == -1) {
                strcat(ptr, ".exe");
            } else {
                int len = strlen(ptr);
                for (int i = count + 1; i < len; ++i) {
                    buf[i] = 0;
                }
                strcat(ptr, "exe");
            }
            printf("%s", ptr);
        }
        default: {
            printf("\n");
        }
    }
}
