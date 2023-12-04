/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:18:33 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/04 14:53:14 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long size)
{
	unsigned long	i;
	unsigned long	d_len;
	unsigned long	s_len;

	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (s_len + size);
	i = 0;
	while (src[i] != '\0' && (d_len + i) < (size - 1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
