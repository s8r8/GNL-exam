#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	int	cont = 0;
	char	*ptr = NULL;
	if (s == NULL)
		return (NULL);
	while (s[cont] != '\0')
		cont++;
	if(!(ptr=malloc(sizeof(char) * cont + 1)))
		return (NULL);
	cont = 0;
	while (*s != '\0')
	{
		ptr[cont] = *s;
		cont++;
		s++;
	}
	ptr[cont] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int cont = 0;
	int i = 0;
	char *ptr = NULL;
	while (s1[cont] != '\0')
		cont++;
	while (s2[i] != '\0')
	{
		cont++;
		i++;
	}
	if (!(ptr = malloc(sizeof(char) * cont + 1)))
		return (NULL);
	cont = 0;
	while (*s1 != '\0')
	{
		ptr[cont] = *s1;
		s1++;
		cont++;
	}
	while(*s2 != '\0')
	{
		ptr[cont] = *s2;
		s2++;
		cont++;
	}
	ptr[cont] = '\0';
	return(ptr);
}

int	ft_strchr(char *s1)
{
	if (s1 == NULL)
		return (0);
	while(*s1 != '\0')
	{
		if (*s1 == '\n')
			return(1);
		s1++;
	}
	if (*s1 == '\n')
		return(1);
	return(0);
}

char	*ft_substr(char *s1, int len)
{
	char *ptr = NULL;
	if(s1 == NULL)
		return(NULL);
	if(!(ptr = malloc(sizeof(char) * len + 1)))
		return(NULL);
	len = 0;
	while (*s1 != '\n')
	{
		ptr[len] = *s1;
		len++;
		s1++;
	}
	ptr[len] = '\0';
	return(ptr);
}

int	get_next_line(char **line)
{
	int			len = 0;
	int 		pos = 0;
	static char	*aux = NULL;
	char		*aux2 = NULL;
	char		buff[BUFFER_SIZE + 1];
	char		*change = NULL;
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
