
#include <stdlib.h> //malloc
#include <stdio.h>

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
	int len;

	i = 0;
	len = 0;
	while(s[len])
		len++;
	if(!(copy = (char *)malloc(len + 1)))
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
	if(*str == c)
		return(str);
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
	str[i]== '\0';
	return (str);
}

int get_next_line(int fd, char **line)
{
	static char *aux;
	char buff[42];
	char *temp;
	int len;

	if(fd < 0 || line == NULL)
		return(-1);
	while((len = read(fd, buff, )))
}

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

