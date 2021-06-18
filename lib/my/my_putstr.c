/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** alizee.soussan@epitech.eu
*/

#include "my.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}
