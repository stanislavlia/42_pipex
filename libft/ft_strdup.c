/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:46:51 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/17 18:46:52 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*array;
	int		i;

	i = 0;
	array = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (array == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		array[i] = src[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

/*
int main()
{
	char s1[] = "";
	char *array;

	array = ft_strdup(s1);
	//array = strdup(s1);
	printf("1st val = %c; last  = %c \n", array[0], array[4]);
}
*/
