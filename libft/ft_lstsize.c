/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:26:31 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/05 16:26:33 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*curr_node;

	len = 0;
	if (lst != NULL)
	{
		curr_node = lst;
		while (curr_node != NULL)
		{
			len++;
			curr_node = curr_node->next;
		}
	}
	return (len);
}
