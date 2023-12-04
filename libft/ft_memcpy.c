/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:17:58 by sliashko          #+#    #+#             */
/*   Updated: 2023/08/27 18:51:05 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned long n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr_d = (unsigned char *)dest;
	ptr_s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*ptr_d = *ptr_s;
		ptr_d++;
		ptr_s++;
		i++;
	}
	return (dest);
}
