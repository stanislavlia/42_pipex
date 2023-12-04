/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:18:45 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/02 17:41:47 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlen(const char *string)
{
	unsigned int	len;

	len = 0;
	while (*string != '\0')
	{
		len++;
		string++;
	}
	return (len);
}
