// Write a C Program to implement Horspool Algorithm for pattern matching

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[256];
char pattern[10], text[100];
int m, n, i, j, k, idx;

int horspool()
{
    for (i = 0; i < n; i++)
        table[text[i]] = m;

    for (j = 0; j <= m - 2; j++)
        table[pattern[j]] = m - 1 - j;

    i = m - 1;
    while (i <= n - 1)
    {
        k = 0;
        while (k <= m - 1 && pattern[m - 1 - k] == text[i - k])
            k++;

        if (k == m)
            return i - m + 1;
        else
            i = i + table[text[i]];
    }

    return -1;
}

void main()
{
    printf("Enter the text with space indicated by '-' or '_':\n");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    n = strlen(text);
    m = strlen(pattern);
    idx = horspool();

    for (k = 0; k < m;)
    {
        if (text[idx++] == pattern[k++])
            continue;
        else
            break;
    }

    if (k == m)
        printf("Pattern is found\n");
    else
        printf("Pattern in not found\n");
}