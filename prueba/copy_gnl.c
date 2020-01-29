

#include "gnl.h"

int        ft_strlen(const char *str)
{
    int                    i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    int                    len;
    char                *str;
    int                    i;
    int                    i2;

    i = -1;
    i2 = 0;
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2);
    str = malloc(len + 1);
    if (str == NULL)
        return (NULL);
    while (s1[++i] != '\0')
        str[i2++] = s1[i];
    i = -1;
    while (s2[++i] != '\0')
        str[i2++] = s2[i];
    str[i2] = '\0';
    return (str);
}

char    *ft_strdup(const char *s1)
{
    char                *space;
    int                    i;
    int                    len;

    i = 0;
    len = 0;
    while (s1[len] != '\0')
        len++;
    space = (char*)malloc(len + 1);
    if (space == NULL)
        return (0);
    while (s1[i] != '\0')
    {
        space[i] = s1[i];
        i++;
    }
    space[i] = '\0';
    return (space);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char                *str;
    unsigned long int    i;
    unsigned int        str_len;

    i = 0;
    if (s == NULL)
        return (NULL);
    if (!(str = (char*)malloc(len + 1)))
        return (NULL);
    str_len = ft_strlen(s);
    if (start > str_len)
    {
        str[i] = '\0';
        return (str);
    }
    while (len > i)
    {
        str[i] = s[i + start];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *ft_strchr(const char *s, int c)
{
    char                *str;

    str = (char *)s;
    while (*str != '\0')
    {
        if (*str == c)
            return (str);
        str++;
    }
    if (*str == c)
        return (str);
    if (c == 0)
        return ("\0");
    return (NULL);
}


int    ft_new_line(char **line, char *aux)
{
    int        len;
    char    *temp;

    len = 0;
    while (aux[len] != '\0' && aux[len] != '\n')
        len++;
    if (aux[len] == '\n')
    {
        *line = ft_substr(aux, 0, len);
        temp = ft_strdup(&(aux[len + 1]));
        free(aux);
        aux = temp;
    }
    else
    {
        *line = ft_strdup(aux);
        free(aux);
        aux = NULL;
        return (0);
    }
    return (1);
}


int    ft_return_value(int len, char **line, char *aux)
{
    if (len < 0)
        return (-1);
    else if (len == 0 && aux == NULL)
    {
        *line = ft_strdup("");
        return (0);
    }
    else
        return (ft_new_line(line, aux));
}

int    ft_get_next_line(char **line)
{
    static char    *aux;
    char        buff[42];
    char        *temp;
    int            len;

    if (line == NULL)
        return (-1);
    while ((len = read(0, buff, 41)) > 0)
    {
        buff[len] = '\0';
        if (!aux)
            aux = ft_strdup(buff);
        else
        {
            temp = ft_strjoin(aux, buff);
            free(aux);
            aux = temp;
        }
        if (ft_strchr(aux, '\n'))
            break ;
    }
    return (ft_return_value(len, line, aux));
}
