/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** alizee.soussan@epitech.eu
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);
    return (0);
}
