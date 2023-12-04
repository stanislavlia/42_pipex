/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:36:38 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/05 16:36:40 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr_node;

	if (lst == NULL)
		return (NULL);
	curr_node = lst;
	while (curr_node->next != NULL)
	{
		curr_node = curr_node->next;
	}
	return (curr_node);
}

// #include <stdio.h>
// int	main()
// {
//     t_list	*list = NULL; // Initialize list to NULL
//     t_list	*node1, *node2, *node3;

//     node1 = ft_lstnew("Mama");
//     if (node1 == NULL)
//         return (1);

//     node2 = ft_lstnew("Papa");
//     if (node2 == NULL)
//         return (1);

//     node3 = ft_lstnew("sister");
//     if (node3 == NULL)
//         return (1);

//    ft_lstadd_front(&list, node1);
//    ft_lstadd_front(&list, node2);
//    ft_lstadd_front(&list, node3);

// 	printf("Last content: %s\n", ft_lstlast(list)->content);
// }
