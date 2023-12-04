/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:00:58 by sliashko          #+#    #+#             */
/*   Updated: 2023/11/30 20:48:34 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	uc;
	char			*p;

	uc = (unsigned char)c;
	p = NULL;
	while (*str != '\0')
	{
		if (*str == uc)
			p = (char *)str;
		str++;
	}
	if (uc == '\0')
		return ((char *)(str));
	return (p);
}
