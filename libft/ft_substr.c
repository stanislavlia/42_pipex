/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:34:23 by sliashko          #+#    #+#             */
/*   Updated: 2023/11/30 20:48:46 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_substring(char *dest, const char *src,
						unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[len] = '\0';
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;

	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (s_len - start < len)
		len = s_len - start;
	substr = (char *) malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	copy_substring(substr, s, start, len);
	return (substr);
}

/*

//test part
//this func is from github
char
	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
#include <stdio.h>

int	main()
{
	printf("Test #1\n");
	printf("%s\n", ft_substr("Hello worlddd", 100, 1000));
	printf("%s\n", ft_substr2("Hello worlddd", 100, 1000));

		printf("Test #2\n");
	printf("%s\n", ft_substr("", 0, 3));
	printf("%s\n", ft_substr2("", 0, 3));
	printf("Test #3\n");
	printf("%s\n", ft_substr("Hello worlddd", 0, 3));
	printf("%s\n", ft_substr2("Hello worlddd", 0, 3));

		printf("Test #4\n");
	printf("%s\n", ft_substr("Hello worlddd", 2, 10));
	printf("%s\n", ft_substr2("Hello worlddd", 2, 10));
}
*/
