#include "gnl.h"


char	*ft_substr(char *s, int len)
{
	char *ptr;
	if (!(ptr = malloc(sizeof(char) * len + 1)))
		return(NULL);
		len = 0;
	while (*s != '\n')
	{
		ptr[len] = *s;
		len++;
		s++;
	}
	ptr[len] = '\0';
	return (ptr);
}
char	*ft_strdup(char *s1)
{
	int cont = 0;
	char *ptr;
	while(s1[cont] != '\0')
		cont++;
	if (!(ptr = malloc(sizeof(char) * cont + 1)))
		return (NULL);
	cont = 0;
	while (*s1 != '\0')
	{
		ptr[cont] = *s1;
		s1++;
		cont++;
	}
	ptr[cont] = '\0';
	return (ptr);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int cont = 0;
	int i = 0;
	char *ptr;
	if (!s1 || !s2)
		return (NULL);
	while (s1[cont] != '\0')
		cont++;
	while (s2[i] != '\0')
	{
		cont++;
		i++;
	}
	if (!(ptr = malloc(sizeof(char) * cont + 1)))
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		ptr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		ptr[i] = *s2;
		i++;
		s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}
int	ft_strchr(char *s)
{
	while (*s != '\0')
	{
		if (*s == '\n')
			return(1);
		else
			s++;
	}
	return(0);
}
int	ft_get_next_line(char **line)
{
	char	*buff;
	int	len = 0;
	static char	*aux = NULL;
	char *aux2 = NULL;
	int	pos = 0;
	char *change = NULL;
	if (line == NULL)
		return (-1);
	if (!(buff = malloc(sizeof(char)* (42 + 1))))
		return(0);
	while ((len = read(0, buff, 42)) > 0)
	{
		buff[len] = '\0';
		if (aux == NULL)
			aux = ft_strdup(buff);
		else
			{
				aux2 = ft_strjoin(aux, buff);
				free(aux);
				aux = aux2;
			}
		if (ft_strchr(aux) == 1)
			break;
	}
	free(buff);
	if (len < 0)
		return (-1);
	if (len == 0 && aux == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	while (aux[pos] != '\n' && aux[pos] != '\0')
		pos++;
	if (aux[pos] == '\n')
	{
		*line = ft_substr(aux, pos);
		change = ft_strdup(aux + (pos+1));
		free(aux);
		aux = change;
		if(aux[0] == '\0')
		{
			free(aux);
			aux = NULL;
		}
		return (1);
	}
	else
	{
		*line = ft_strdup(aux);
		free(aux);
		aux = NULL;
		return (0);
	}
}
