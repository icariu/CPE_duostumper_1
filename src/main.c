/*
** EPITECH PROJECT, 2020
** CPE_duostumper_1_2019
** File description:
** main
*/

#include "my.h"
#include <stddef.h>
#include <unistd.h>

char *check_char(char *str)
{
    char *imp_char = "cnqv";
    static char *flags = "\0";

    if (str == NULL)
        return (flags);
    for (int i = 1; str[i]; i++)
        for (int j = 0; imp_char[j]; j++)
            if (str[i] == imp_char[j])
                flags = my_strcatchar(flags, str[i]);
    return (flags);
}

int check_dash(char *str)
{
    if (str[0] != '-')
        return (-2);
    if (str[0] == '-')
        check_char(str);
    return (0);
}

void my_putstrerr(char *str, int i)
{
    for (; str[i]; i++)
        write(2, my_strcatchar("\0", str[i]), 1);
}

int check_error_dash(char *str)
{
    if (str[0] != '-')
        return (-1);
    for (int i = 1; str[i]; i++) {
        if (str[i] != 'c' && str[i] != 'n' && str[i] != 'q' && str[i] != 'v') {
            write(2, "tail: invalid option -- '", 25);
            write(2, my_strcatchar("\0", str[i]), 1);
            write(2, "'\nTry 'tail --help' for more information.\n", 42);
            return (84);
        } if (str[i] == 'c' && str[i + 1] != '\0') {
            write(2, "tail: invalid number of bytes: '", 32);
            my_putstrerr(str, i+1);
            write(2, "'\n", 2);
            return (84);
        } if (str[i] == 'n' && str[i + 1] != '\0') {
            write(2, "tail: invalid number of lines: '", 32);
            my_putstrerr(str, i+1);
            write(2, "'\n", 2);
            return (84);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    int error = 0;

    if (ac == 1 || (ac == 2 && my_strcmp(av[1], "-") == 0)) {
        read_func();
        return (0);
    } if (checker(ac, av) == 1)
        error = 1;
    for (int i = 0; av[i]; i++)
        if (check_error_dash(av[i]) == 84)
            return (1);
    for (int i = 0; av[i]; i++)
        check_dash(av[i]);
    get_right_flags(av);
    return (error);
}
