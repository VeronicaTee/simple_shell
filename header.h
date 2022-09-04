#ifndef HEADER_H
#define HEADER_H

char **prompt(void);
char usage(int, int, char *);
void replace_expr(char *, int, char **);



void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);




#endif
