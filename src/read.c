/*
** EPITECH PROJECT, 2020
** CPE_duostumper_1_2019
** File description:
** read
*/

#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

void read_func(void)
{
    int i = 1;
    char *buffer = malloc(sizeof(char) * 4097);
    char *res = "\0";

    while (i != 0) {
        i = read(0, buffer, 4096);
        if (i == 0)
            break;
        res = my_strcat(res, buffer);
    }
    my_putstr(res);
}

void write_ten_lines(char *str)
{
    char **tab = my_str_to_word_array(str, '\n');
    int i = 0;
    
    for (; tab[i]; i++);
    if (i >= 10)
        i -= 10;
    for (; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

void simple_tail(char **av)
{
    int fd = 0;
    char *buffer = malloc(sizeof(char) * 4097);
    int r = 1;
    char *res = "\0";

    for (int i = 1; av[i]; i++) {
        fd = open(av[i], O_RDONLY);
        if (fd == -1)
            return;
        while (r != 0) {
            r = read(fd, buffer, 4096);
            if (r == 0)
                break;
            res = my_strcat(res, buffer);
        }
        close(fd);
        write_ten_lines(res);
        res = "\0";
        r = 1;
    }
}

void get_right_flags(char **av)
{
    char *tmp = NULL;
    int q = 0, v = 0, c = 0, n = 0;

    tmp = check_char(tmp);
    if (my_strlen(tmp) == 0)
        simple_tail(av);
    for (int i = 0; tmp[i]; i++) {
        if (tmp[i] == 'q') {
            q++;
            v = 0;
        } if (tmp[i] == 'v') {
            v++;
            q = 0;
        } if (tmp[i] == 'c') {
            c++;
            n = 0;
        } if (tmp[i] == 'n') {
            n++;
            c = 0;
        }
    }
}
