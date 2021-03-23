#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void memory_corruption(char *s) {
    char *buf = (char *) malloc(sizeof(char)*8);
    strcpy(buf, s);

    char d[8];
    char *o = (char *) malloc(sizeof(char)*8);
    int i;
    scanf("%d", &i);
    strncpy(d, &o[i], 8);

    free(o);
    strncpy(d, &o[0], 8);

    o = (char *) malloc(sizeof(char)*100000000000);
    printf("%s", o);
}

void strings(char *s) {
    printf(s);

    char a[2];
    char b[] = {'a'};
    strcpy(a, b);

    char c[10];
    scanf("%s", c);
    system(c);

    char password[] = "SECRETPASS";
    char in[11];
    scanf("%s", in);
    if (!strcmp(password, in)) {
        printf("Authenticated");
    }
}

void type() {
    int a = 500;
    int b;
    scanf("%d", &b);
    size_t l = a - b;
    char *o = (char *) malloc(sizeof(char)*l);

    a = 2147483647;
    b = a + 1;
}

int main(int argc, char **argv) {
    memory_corruption(argv[1]);
    strings(argv[1]);
    type();
    return 0;
}
