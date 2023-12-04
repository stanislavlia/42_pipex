/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:44:53 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/05 17:44:56 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr_node;

	if (lst == NULL || f == NULL)
		return ;
	curr_node = lst;
	while (curr_node != NULL)
	{
		f(curr_node->content);
		curr_node = curr_node->next;
	}
}
