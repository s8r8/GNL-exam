
#include "gnl.h"

//Len
int ft_strlen(const char *str)
{
	int len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}
//Copia de la cadena
char *ft_strdup(const char *s)
{
	char *copy;
	int i;

	i = 0;
	if(!(copy = (char *)malloc(ft_strlen(s) + 1)))
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
char *ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while(*str != '\0')
	{
		if(*str == c)
			return(str);
		str++;
	}
	if(c == 0)
		return ("\0");
	return (NULL);
}

//Crea una cadena de caracteres que comienza en el índice ’start’ y tiene como tamaño máximo ’len’.)
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;
	unsigned long int i;
	unsigned int str_len;

	i = 0;
	if(s == NULL)
		return(NULL);
	if(!(str = malloc(len + 1)))
		return(NULL);
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

int ft_next_line(char **line, char *aux)
{
    int len;
    char *temp;
    
    len = 0;
    while(aux[len] != '\0' && aux[len] != '\n')
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
        return(0);
    }
    return (1);
}

int ft_return_value(int len, char **line, char *aux)
{
    if (len < 0)
        return(-1);
    else if(len == 0 && aux == NULL)
    {
        *line = ft_strdup("");
        return(0);
        
    }
    else
        return(ft_next_line(line, aux));
}

int ft_get_next_line(char **line)
{
	static char *aux;
	char buff[42];
	char *temp;
	int len;

	if(line == NULL)
		return(-1);
	while((len = read(0, buff, 41)) > 0)
    {
        buff[len] = 0;
        if (!aux)
            aux = ft_strdup(buff);
        else{
            temp = ft_strjoin(aux, buff);
            free(aux);
            aux = temp;
        }
        if(ft_strchr(aux, '\n'))
            break ;
    }
    return(ft_return_value(len, line, aux));
}
/*
int main()
{
	char *s1 = "Hello ";
	char *s2 = "everyone";
	char *str;
	char *str2;

	printf("%s", ft_strjoin(s1, s2));
	str = ft_strdup(s2);
	printf("\n%s\n", str);
	str2 = ft_strchr(s1, ' ');
	printf("%s", str2);
}
*/
