#include "main.h"

int get_endianness(void) {
    unsigned int num = 1;
    char *endian = (char *)&num;
    return (*endian == 1);
}

