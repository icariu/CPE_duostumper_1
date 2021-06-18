/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** alizee.soussan@epitech.eu
*/

int my_is_prime(int nb)
{
    int x = 2;

    if (nb < 2)
        return (0);
    while (x != nb) {
        if (nb % x == 0)
            return (0);
        x++;
    }
    return (1);
}
