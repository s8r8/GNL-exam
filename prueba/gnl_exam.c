
#include "get_next_line.h"

//Len
int ft_strlen(const char *str)
{
	int len;

	len = 0;
	while(str[len] != '\0')
		len++;
	return (len);
}
//Copia de la cadena
char *ft_strdup(const char *s)
{
	char *copy;
	int i;

	i = 0;
	if(!(copy = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while(s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);

}

//Unir una cadena con otra
char *ft_strjoin(char const *s1, char const *s2)
{
	int len;
	char *str;
	int i;

	i = 0;
	if(s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if(!(str = malloc(len + 1)))
		return (NULL);
	while(*s1 != '\0')
	{
		str[i++] = *s1;
		s1++;
	}
	while(*s2 != '\0')
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

//Devuelve un puntero a la última aparición del caracter c en la cadena s
char *ft_strchr(char *s)
{
	
	while(*s != '\0')
	{
		if(*s == '\n')
			return(1);
		s++;
	}
    if (*str == '\n')
        return (1);
	return (0);
}

//Crea una cadena de caracteres que comienza en el índice ’start’ y tiene como tamaño máximo ’len’.)
char	*ft_substr(char const *s, int len)
{
	char *str;
	int i;

	i = 0;
	if(s == NULL)
		return(NULL);
	if(!(str = (char*)malloc(len + 1)))
		return(NULL);
	while (len > i)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int    get_next_line(char **line)
{
    int            len = 0;
    int         pos = 0;
    static char    *aux = NULL;
    char        *aux2 = NULL;
    char        buff[BUFFER_SIZE + 1];
    char        *change = NULL;
    if (!line)
        return (-1);
    if (!aux)
        aux = ft_strdup("");
    if (ft_strchr(aux)!= 1)
    {
        while ((len = read(0,buff,BUFFER_SIZE)) > 0)
        {
            buff[len] = '\0';
            change = ft_strjoin(aux, buff);
            free(aux);
            aux = change;
            
            if (ft_strchr(aux) == 1)
                break;
        }
    }
    if (len < 0)
        return (-1);
    else if (len == 0 && !aux)
    {
        *line = ft_strdup("");
        return (0);
    }
    while (aux[pos] != '\n' && aux[pos] != '\0')
        pos++;
    if (aux[pos] == '\n')
    {
        *line = ft_substr(aux,pos);
        aux2 = ft_strdup(aux + (pos + 1));
        free (aux);
        aux = aux2;
        if (*aux == '\0')
        {
            free(aux);
            aux = NULL;
        }
        return (1);
    }
    *line = ft_strdup(aux);
    free(aux);
    aux = NULL;
    return (0);
}
