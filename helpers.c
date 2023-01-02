#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;
	char 	*ptr;

	ret = 0;
	sign = 1;
	ptr = (char *)nptr;
	if(!ptr)
		return (0);
	while(*ptr >= 0 && *ptr <= 32)
		ptr++;
	if(*ptr == '-' || *ptr == '+')
	{
		if(*ptr == '-')
			sign = -1;
		ptr++;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		ret = ret * 10 + (*ptr - '0');
		ptr++;
	}
	return (sign * ret);
}

long long	ft_atol(const char *nptr)
{
	long long	ret;
	long long	sign;
	char 	*ptr;

	ret = 0;
	sign = 1;
	ptr = (char *)nptr;
	if(!ptr)
		return (0);
	while(*ptr >= 0 && *ptr <= 32)
		ptr++;
	if(*ptr == '-' || *ptr == '+')
	{
		if(*ptr == '-')
			sign = -1;
		ptr++;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		ret = ret * 10 + (*ptr - '0');
		ptr++;
	}
	return (sign * ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while(s[i++]);
	return (i - 1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*str;
	const char 	*ptr;
	size_t		i;

	if(!dest && !src)
		return (NULL);
	if(dest == src)
		return (NULL);
	str = (char *)dest;
	ptr = (const char *)src;
	i = 0;
	while(i < n)
	{
		str[i] = ptr[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	
	len = ft_strlen(src);
	if(!size)
		return (len);
	if(len >= size)
		len = size - 1;
	ft_memcpy(dest, src, len);
	dest[len] = 0;
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;

	if(!s)
		return (NULL);
	s_len = ft_strlen(s);
	if(s_len <= start)
	{	
		len = 0;
		start = s_len;
	}
	if(len > s_len - start)
		len = s_len - start;
	ret = malloc(sizeof(char) * (len + 1));
	if(!ret)
		return (NULL);
	ft_strlcpy(ret, &s[start], len + 1);
	return (ret);
}

size_t	len_word(char const *s, char c)
{
	size_t	len;
	
	len = 0;
	while(s[len] && s[len] != c)
		len++;
	return (len);
}

char	*ft_add_str(char *s, char c)
{
	size_t	len;
	char	*str;

	len = len_word(s, c);
	str = ft_substr(s, 0, len);
	return (str);
}

char	**ft_free_split(char **arr, int	size)
{
	int	i;

	i = 0;
	while(i < size)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

int	word_count(char const *s, char c)
{
	int		wc;
	int 	i;

	wc = 0;
	i = 0;
	while(s[i])
	{
		while(s[i] && s[i] == c)
			i++;
		if(s[i])
			wc++;
		while(s[i] && s[i] != c)
			i++; 
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	wc;
	char	**ret;
	char	*str;

	if(!s)
		return (NULL);
	wc = word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (wc + 1));
	if(!ret)
		return (NULL);
	i = 0;
	str = (char *)s;
	while(i < wc)
	{
		while(*str == c)
			str++;
		ret[i] = ft_add_str(str, c);
		if(ret[i] == NULL)
			return(ft_free_split(ret, i - 1));
		str += ft_strlen(ret[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int	ft_tab_size(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
		i++;
	return (i);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_isdigit(int c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (0);
}