/*
** EPITECH PROJECT, 2020
** PSU_matthieu
** File description:
** obj_64
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my_objdump.h"

static void print_hexa(Elf64_Shdr shs, unsigned int index, Elf64_Ehdr *buff)
{
    char hexa;
    for (;index != shs.sh_size;) {
        hexa = (((char *)buff) + shs.sh_offset)[index];
        printf("%02x", (unsigned char)hexa);
        index++;
        if (!(index % 16)) {
            printf("  ");
            if (index >= shs.sh_size && index % 16 != 0)
                is_space_hexa(index);
            return;
        }
        if (!(index % 4))
            printf(" ");
    }
    if (index >= shs.sh_size && index % 16 != 0)
        is_space_hexa(index);
}

static void in_section(Elf64_Ehdr *buff, Elf64_Shdr shs)
{
    unsigned int index = 0;
    char *hexa = (((char *)buff) + shs.sh_offset);
    unsigned int address = (unsigned int)shs.sh_addr;
    for (;index < shs.sh_size;) {
        if (!(index % 16)) {
            printf(" %04x ", address);
            address += 16;
            print_hexa(shs, index, buff);
        }
        if (hexa[index] > 31 && hexa[index] < 127)
            printf("%c", hexa[index]);
        else
            printf(".");
        index++;
        if (!(index % 16))
	        printf("\n");
    }
    if (index >= shs.sh_size && index % 16 != 0) {
        is_space(index);
    }
}

static void start_parsing(Elf64_Ehdr *buff, char *path)
{
    Elf64_Shdr *shs = (Elf64_Shdr*)((void *)buff + buff->e_shoff);
    Elf64_Shdr section = shs[buff->e_shstrndx];
    char *strtab = ((void *)buff + section.sh_offset);
    for (int i = 0; i < buff->e_shnum; i++) {
        bool look = true;
        if ((strtab + shs[i].sh_name)[0] == '\0' ||
        strcmp(strtab + shs[i].sh_name, ".strtab") == 0 ||
        strcmp(strtab + shs[i].sh_name, ".shstrtab") == 0 ||
        strcmp(strtab + shs[i].sh_name, ".symtab") == 0 ||
        strcmp(strtab + shs[i].sh_name, ".bss") == 0) {
            look = false;
        } if (!strncmp(".rela", strtab + shs[i].sh_name, 5)) {
            look = false;
        } if (!strcmp(strtab + shs[i].sh_name, ".rela.dyn") ||
        !strcmp(strtab + shs[i].sh_name, ".rela.plt"))
            look = true;
        if (shs[i].sh_size != 0 && look == true) {
            printf("Contents of section %s:\n", strtab + shs[i].sh_name);
            in_section(buff, shs[i]);
        }
    }
}

void start_objdump64(Elf64_Ehdr *buff, char *path)
{
    printf("\n%s:     file format elf64-x86-64\n", path);
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
    printf("start address 0x%016lx\n\n", buff->e_entry);
    start_parsing(buff, path);
    return;
}