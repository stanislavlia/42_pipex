/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:56:01 by sliashko          #+#    #+#             */
/*   Updated: 2023/08/30 20:06:30 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_size(int num)
{
	int	size;

	if (num < 0)
		num = -num;
	size = 1;
	while (num / 10 > 0)
	{
		size++;
		num = (num / 10);
	}
	return (size);
}

static int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	val;

	if (power < 0)
		return (0);
	val = 1;
	i = 0;
	while (i < power)
	{
		val = val * nb;
		i++;
	}
	return (val);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static void	fill_num_str(char *num_str, int number, int num_size)
{
	int	i;

	i = 1;
	while (i <= num_size)
	{
		num_str[i - 1] = (number / ft_iterative_power(10, num_size - i)) + '0';
		number = number % ft_iterative_power(10, num_size - i);
		i++;
	}
	num_str[num_size] = '\0';
}

char	*ft_itoa(int n)
{
	char	*result;
	char	*num_str;
	int		num_size;
	int		number;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 1;
	number = ft_abs(n);
	num_size = ft_number_size(number);
	num_str = (char *)malloc(sizeof(char) * (num_size + 1));
	if (num_str == NULL)
		return (NULL);
	fill_num_str(num_str, number, num_size);
	num_str[num_size] = '\0';
	if (n < 0)
	{
		result = ft_strjoin("-", num_str);
		free(num_str);
		return (result);
	}
	return (num_str);
}

/*
int	main()
{
	printf("str of number = %s\n", ft_itoa(-711711711));
	printf("str of number = %s\n", ft_itoa(923));
	printf("str of number = %s\n", ft_itoa(-7832));
	printf("str of number = %s\n", ft_itoa(-01));
	printf("str of number = %s\n", ft_itoa(100));
	printf("str of number = %s\n", ft_itoa(12));
	printf("str of number = %s\n", ft_itoa(-2147483648));
	printf("str of number = %s\n", ft_itoa(2147483647));
}
*/
