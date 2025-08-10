#include "philosophers_bonus.h"
#include "stdlib.h"
#include "unistd.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;
	size_t	i;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

size_t	ft_atoui(const char *str)
{
	int		sign;
	size_t	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	ft_putendl(char *str, int fd)
{
	size_t	len;

	len = ft_strlen(str);
	write(fd, str, len);
	write(fd, NEWLINE, 1);
}
