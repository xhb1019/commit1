
#ifndef TRANSLATE_UTILS_H
#define TRANSLATE_UTILS_H

#include <stdint.h>
#include <stdio.h>

typedef enum {
  IMM_NONE,      /* No immediate value */
  IMM_12_SIGNED, /* 12-bit signed number */

  /* IMPLEMENT ME */
  /* === start === */
  IMM_5_UNSIGNED,   // 5位无符号数 (0~31)
  IMM_20_UNSIGNED, 
  IMM_13_SIGNED , // 20位无符号数 (用于U-type)
  IMM_21_SIGNED // 21位有符号数 (用于UJ-type)
   
  
  
  /* === end === */
} ImmType;

/* Writes the instruction as a string to OUTPUT. NAME is the name of the
   instruction, and its arguments are in ARGS. NUM_ARGS is the length of
   the array.
 */
void write_inst_string(FILE* output, const char* name, char** args,
                       int num_args);

/* Writes the instruction to OUTPUT in hexadecimal format. */
void write_inst_hex(FILE* output, uint32_t instruction);

/* Returns 1 if the label is valid and 0 if it is invalid. A valid label is one
   where the first character is a character or underscore and the remaining
   characters are either characters, digits, or underscores.
 */
int is_valid_label(const char* str);

/* IMPLEMENT ME - see documentation in translate_utils.c */
int is_valid_imm(long imm, ImmType type);

/* IMPLEMENT ME - see documentation in translate_utils.c */
int translate_num(long int* output, const char* str, ImmType type);

/* IMPLEMENT ME - see documentation in translate_utils.c */
int translate_reg(const char* str);

#endif

