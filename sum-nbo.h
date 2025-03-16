#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

void print_hex(uint32_t value);
void print_dec(uint32_t value);
void print_plus();
void print_equal();
uint32_t one_file(char* file);
void many_files(int n, char **files);