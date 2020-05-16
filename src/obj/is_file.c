/*
** EPITECH PROJECT, 2020
** PSU_matthieu
** File description:
** is_file
*/

#include <stdlib.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my_objdump.h"

static void check_mag(char *path, Elf64_Ehdr *buff, int fd)
{
    if (buff->e_ident[EI_MAG0] != ELFMAG0 || buff->e_ident[EI_MAG1] != ELFMAG1
    || buff->e_ident[EI_MAG2] != ELFMAG2 || buff->e_ident[EI_MAG3] != ELFMAG3)
    {
        fprintf(stderr, "objdump: %s: File format not recognized\n", path);
        close(fd);
        exit(84);
    }
    return;
}

static void check_objdump(int fd, struct stat stats, char *path)
{
    void *buff = NULL;
    Elf64_Ehdr *new_buff = NULL;

    if ((buff = mmap(NULL, stats.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
    == (void *)-1) {
        close(fd);
        exit(84);
    }
    new_buff = (Elf64_Ehdr *)buff;
    check_mag(path, new_buff, fd);
    if (new_buff->e_ident[EI_CLASS] == ELFCLASS64)
        start_objdump64(new_buff, path);
    else
        start_objdump32((Elf32_Ehdr *)buff, path);
    return;
}

void is_file(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat	stats;

    if (fd == -1) {
        fprintf(stderr, "objdump: '%s': No such file\n", path);
        close(fd);
        exit(84);
    }
    if (!fstat(fd, &stats))
        check_objdump(fd, stats, path);
    close(fd);
    return;
}