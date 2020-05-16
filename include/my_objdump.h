/*
** EPITECH PROJECT, 2020
** PSU_matthieu
** File description:
** my_objdump
*/

#ifndef MY_OBJDUMP_H_
#define MY_OBJDUMP_H_

#include <elf.h>

void is_file(char *path);

void objdump32(char *path);

void start_objdump64(Elf64_Ehdr *buff, char *path);

#endif /* !MY_OBJDUMP_H_ */
