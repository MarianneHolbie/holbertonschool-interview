#include "holberton.h"
#include <stdio.h>

int wildcmp(char *s1, char *s2)
{
    /* id if same end */
    if (*s2 == '\0')
        return (*s1 == '\0');
    
    /* If s2 is not '*' */
     if (*s2 != '*')
    {
        if (*s1 == '\0' || (*s1 != *s2 && *s2 != '?'))
            return 0;
        return wildcmp(s1 + 1, s2 + 1);
    }

    /* if '*' => next */
    while (*s1 != '\0')
    {
        if (wildcmp(s1, s2 + 1))
            return 1;
        s1++;
    }

    return wildcmp(s1, s2 + 1);
}