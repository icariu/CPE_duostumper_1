/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** alizee.soussan@epitech.eu
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}