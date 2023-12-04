/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:36:03 by sliashko          #+#    #+#             */
/*   Updated: 2023/08/30 19:50:05 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*trimmed;
	size_t		len;

	while (*s1 && in_set(set, *s1))
		s1++;
	start = s1;
	end = s1 + ft_strlen(s1);
	while (end > start && in_set(set, *(end - 1)))
		end--;
	len = end - start;
	trimmed = (char *)malloc(sizeof(char) * (len + 1));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, (char *)start, len + 1);
	return (trimmed);
}
