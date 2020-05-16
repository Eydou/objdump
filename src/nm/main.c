/*
** EPITECH PROJECT, 2020
** PSU
** File description:
** main
*/

#include <stdio.h>

int main(int ac, char **av)
{
    if (ac == 1)
        printf("nm: 'a.out': No such file\n");
    else
        printf("nm: '%s': No such file\n", av[1]);
    return 84;
}