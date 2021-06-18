/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** alizee.soussan@epitech.eu
*/

#include "my.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    } if (nb < 10) {
        my_putchar(48 + nb);
    } if (nb >= 10) {
        my_put_nbr(nb/10);
        my_putchar(48 + nb % 10);
    }
}
