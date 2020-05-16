/*
** EPITECH PROJECT, 2020
** PSU_matthieu
** File description:
** my_objdump
*/

#ifndef MY_OBJDUMP_H_
#define MY_OBJDUMP_H_

#include <elf.h>

#define BFD_NO_FLAGS    0x00
#define HAS_RELOC       0x01
#define EXEC_P          0x02
#define HAS_LINENO      0x04
#define HAS_DEBUG       0x08
#define HAS_SYMS        0x10
#define HAS_LOCALS      0x20
#define DYNAMIC         0x40
#define WP_TEXT         0x80
#define D_PAGED         0x100

void is_file(char *path);

void start_objdump32(Elf32_Ehdr *buff, char *path);

void start_objdump64(Elf64_Ehdr *buff, char *path);

#endif /* !MY_OBJDUMP_H_ */
