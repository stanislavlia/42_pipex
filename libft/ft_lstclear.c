/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:28:15 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/05 17:28:24 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr_node;
	t_list	*next_copy;

	if (lst == NULL || del == NULL)
		return ;
	curr_node = *lst;
	while (curr_node != NULL)
	{
		next_copy = curr_node->next;
		ft_lstdelone(curr_node, del);
		curr_node = next_copy;
	}
	*lst = NULL;
}
