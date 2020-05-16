/*
** EPITECH PROJECT, 2020
** PSU_matthieu
** File description:
** is_space
*/

#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my_objdump.h"

void is_space(unsigned int index)
{
    for (;index % 16 != 0;) {
        printf(" ");
        index++;
    }
    printf("\n");
    return ;
}

void is_space_hexa(unsigned int index)
{
    for (;index % 16 != 0;)
    {
        printf("  ");
        index++;
        if (!(index % 4))
            printf(" ");
        if (!(index % 16))
            printf(" ");
    }
}