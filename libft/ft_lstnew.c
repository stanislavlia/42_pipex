/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:33:37 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/05 15:33:44 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// #include <stdio.h>
// int	main()
// {
// 	t_list	*my_node, *my_node2;

// 	my_node = ft_lstnew("Privet mama!");
// 	my_node2 = ft_lstnew("Privet papa!");
// 	printf("my node content: %s\n", my_node->content);
// 	printf("my node2 content: %s\n", my_node2->content);
// }
