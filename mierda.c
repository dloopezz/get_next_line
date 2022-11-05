#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int main()
{
    char *line = "hello";
    line = (char *)malloc(6);
    bzero(line, 5);
    printf("%s", line);
    return (0);
}