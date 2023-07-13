#ifndef MALLOC_H
#define MALLOC_H
void *malloc_checked(unsigned int b);
int is_valid_number(char *str);
int _putchar(char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
#endif
