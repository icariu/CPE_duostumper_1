/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** alizee.soussan@epitech.eu
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);
    return (1);
}
