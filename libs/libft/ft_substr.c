/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:02:16 by egiacomi          #+#    #+#             */
/*   Updated: 2021/06/19 18:02:16 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	news = malloc(sizeof(char) * (len + 1));
	if (!news)
		return (NULL);
	i = -1;
	while (++i < len && s[start])
		news[i] = s[start++];
	news[i] = '\0';
	return (news);
}
