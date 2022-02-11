/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:59:19 by egiacomi          #+#    #+#             */
/*   Updated: 2021/06/19 17:59:19 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*ft_free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	ft_count(const char *s, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i] && s[i] != sep)
			count++;
		while (s[i] && s[i] != sep)
			i++;
	}
	return (count);
}

static int	ft_countlen(const char *s, int i, char sep)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != sep)
	{
		i++;
		len++;
	}
	return (len);
}

static char	*ft_splitcpy(const char *s, int start, char c)
{
	int		len;
	char	*strs;

	len = ft_countlen(s, start, c);
	strs = ft_substr(s, start, len);
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		count;
	int		start;
	int		i;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	splitted = (char **)malloc(sizeof(char *) * (count + 1));
	if (splitted == NULL)
		return (NULL);
	splitted[count] = 0;
	start = -1;
	i = 0;
	while (i < count)
	{
		if (s[++start] && s[start] != c)
		{
			splitted[i] = ft_splitcpy(s, start, c);
			if (!splitted[i++])
				return ((char **)ft_free_split(splitted));
			start += ft_countlen(s, start, c);
		}
	}
	return (splitted);
}
