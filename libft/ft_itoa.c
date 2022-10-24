/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:52:59 by mdoroana          #+#    #+#             */
/*   Updated: 2022/02/28 14:07:58 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_dig(int n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (1 + ft_count_dig(n / 10));
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_count_dig(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
