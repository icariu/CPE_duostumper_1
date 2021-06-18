/*
** EPITECH PROJECT, 2019
** my_nblen
** File description:
** alizee.soussan@epitech.eu
*/

int my_nblen(int nb)
{
    int ln = 1;

    while (nb > 9) {
        ln++;
        nb /= 10;
    }
    return (ln);
}
