/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** alizee.soussan@epitech.eu
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strcat_slash(char *src, char *dest)
{
    int j = 0;
    int i = 0;
    char *res;

    for (i; dest[i]; i++);
    for (j; src[j]; j++);
    res = malloc(sizeof(char) * (i + j + 2));
    if (res == NULL)
        return (NULL);
    res[0] = '\0';
    for (int x = 0; src[x]; x++)
        res[x] = src[x];
    res[j] = '/';
    for (int x = 0; dest[x]; x++)
        res[x + j + 1] = dest[x];
    res[i + j + 1] = '\0';
    return (res);
}

char *my_strcat(char *src, char *dest)
{
    int j = 0;
    int i = 0;
    char *res;

    for (i; dest[i]; i++);
    for (j; src[j]; j++);
    res = malloc(sizeof(char) * (i + j + 1));
    if (res == NULL)
        return (NULL);
    res[0] = '\0';
    for (int x = 0; src[x]; x++)
        res[x] = src[x];
    for (int x = 0; dest[x]; x++)
        res[x + j] = dest[x];
    res[i + j] = '\0';
    return (res);
}

char *my_strcatchar(char *src, char c)
{
    char *my_char = malloc(2);

    my_char[0] = c;
    my_char[1] = 0;
    return (my_strcat(src, my_char));
}
