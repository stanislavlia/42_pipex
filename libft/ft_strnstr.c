/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:08:12 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/04 15:20:16 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_for_occur(char *ps, char	*substr, size_t len, size_t rem)
{
	size_t	i;

	i = 0;
	if (rem < len)
		return (0);
	while (*ps != '\0' && i < len)
	{
		if (substr[i] != *ps)
		{
			return (0);
		}
		ps++;
		i++;
	}
	if (i == len)
	{
		return (1);
	}
	return (0);
}

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(to_find);
	if (*to_find == '\0')
		return (str);
	if (to_find == NULL || n == 0)
		return (NULL);
	if (len == 0)
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		if (i + len > n)
			break ;
		if (check_for_occur(str + i, to_find, len, n - i) == 1)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
