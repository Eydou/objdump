/*
** EPITECH PROJECT, 2020
** PSU_matthieu
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_objdump.h"

static void start_checking(int ac, char **av)
{
    if (ac == 1) {
        is_file("a.out");
    } else {
        for (int i = 1; i != ac; i++) {
            is_file(av[i]);
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        return 0;
    }
    start_checking(ac, av);
    return 0;
}