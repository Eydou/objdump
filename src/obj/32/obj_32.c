/*
** EPITECH PROJECT, 2020
** PSU_matthieu
** File description:
** obj_32
*/

#include <stdlib.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my_objdump.h"

static void start_begin(Elf32_Ehdr *buff, char *path)
{
    printf("\n%s:     file format elf32-i386\n", path);
    if (buff->e_machine == EM_X86_64) {
        printf("architecture: i386:x86-64, ");
    } else if (buff->e_machine == EM_386)
        printf("architecture: i386, ");
    if (buff->e_type == ET_EXEC)
        printf("flags %010p:\nEXEC_P, HAS_SYMS, D_PAGED\n",
        (EXEC_P + D_PAGED + HAS_SYMS));
    else if (buff->e_type == ET_DYN)
        printf("flags %010p:\nHAS_SYMS, DYNAMIC, D_PAGED\n",
        (DYNAMIC + D_PAGED + HAS_SYMS));
    else if (buff->e_type == ET_REL)
        printf("flags %010p:\nHAS_RELOC, HAS_SYMS\n",
        (HAS_RELOC + HAS_SYMS));
    printf("start address 0x0%lx\n\n", buff->e_entry);
    return;
}

void start_objdump32(Elf32_Ehdr *buff, char *path)
{
    start_begin(buff, path);
    return;
}