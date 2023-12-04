/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:18:20 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/02 13:14:55 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, unsigned long num)
{
	unsigned char	val_to_set;
	size_t			i;
	unsigned char	*char_p;

	val_to_set = val;
	char_p = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		*char_p = (unsigned char)val_to_set;
		char_p++;
		i++;
	}
	return (ptr);
}
