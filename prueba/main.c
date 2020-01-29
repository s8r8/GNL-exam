#include "gnl.h"

int
    main(void)
{
    int        r;
    char    *line;

    line = NULL;
    while ((r = ft_get_next_line(&line)) > 0)
    {
        printf("%s\n", line);
        free(line);
        line = NULL;
    }
    printf("%s", line);
    free(line);
    line = NULL;
}
