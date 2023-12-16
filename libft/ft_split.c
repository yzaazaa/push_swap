/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 04:30:02 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/16 01:32:34 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:56:10 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/04 04:29:05 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	size;
	int	i;

	size = 0;
	i = 1;
	if (!*s)
		return (1);
	if (ft_strlen(s) == 1 && s[0] != 'c')
		return (2);
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		if ((s[i] == c || !s[i])
			&& s[i - 1] != c)
			size++;
		if (!s[i])
			break ;
		i++;
	}
	return (size + 1);
}

static int	strlen_sep(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	*ft_free(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		nb_words;
	int		j;

	if (!s)
		return (NULL);
	nb_words = word_count(s, c);
	ret = malloc(sizeof(char *) * nb_words);
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_words - 1)
	{
		while (s[j] && s[j] == c)
			j++;
		ret[i] = ft_substr(s + j, 0, strlen_sep(s + j, c));
		if (!ret[i++])
			return (ft_free(ret));
		j += strlen_sep(s + j, c) + 1;
	}
	ret[nb_words - 1] = NULL;
	return (ret);
}
