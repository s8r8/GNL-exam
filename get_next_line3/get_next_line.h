#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	get_next_line(char **line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif
#endif
