/*
** EPITECH PROJECT, 2020
** CPE_duostumper_1_2019
** File description:
** checker
*/

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "my.h"

int check_file(char *av)
{
    int fd = open(av, O_DIRECTORY);

    if (fd != -1)
        return (1);
    else
        return (0);
}

int checker(int ac, char **av)
{
    int file = 0;

    if (ac == 1)
        return (0);
    for (int i = 1; av[i] != NULL; i++)
        if (av[i][0] != '-' && file == 0) {
            file = check_file(av[i]);
            break;
        }
    if (file == 0)
        return (1);
    return (0);
}
