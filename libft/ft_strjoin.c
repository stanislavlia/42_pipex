/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:09:41 by sliashko          #+#    #+#             */
/*   Updated: 2023/08/29 17:20:01 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*common_str;
	int		i;

	i = 0;
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	common_str = (char *)malloc(sizeof(char) * total_len);
	if (common_str == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		common_str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		common_str[i] = *s2;
		s2++;
		i++;
	}
	common_str[i] = '\0';
	return (common_str);
}
