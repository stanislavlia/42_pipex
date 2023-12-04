/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:16:27 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/02 12:47:38 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *p, size_t size)
{
	size_t			i;
	unsigned char	*p_byte;

	i = 0;
	p_byte = (unsigned char *)p;
	while (i < size)
	{
		*p_byte = 0;
		p_byte++;
		i++;
	}
}
