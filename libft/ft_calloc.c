/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:39:52 by sliashko          #+#    #+#             */
/*   Updated: 2023/08/28 20:56:49 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_el, size_t element_size)
{
	void	*memory;

	memory = malloc(num_el * element_size);
	if (memory == NULL)
		return (NULL);
	ft_memset(memory, 0, num_el * element_size);
	return (memory);
}
