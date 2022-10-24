/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:55:56 by mdoroana          #+#    #+#             */
/*   Updated: 2022/03/28 16:03:49 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	ft_writenb(int nb, int counter)
{
	if (nb > 9 || nb < -9)
		counter += ft_writenb(nb / 10, counter);
	counter += ft_putchar((nb % 10) * ((nb > 0) - (nb < 0)) + 48);
	return (counter);
}

int	ft_putnbr(int nb)
{
	int	counter;

	counter = 0;
	if (nb < 0)
		ft_putchar('-');
	return ((nb < 0) + ft_writenb(nb, counter));
}

int	ft_putul(t_lu nb, char *str, int base, int counter)
{
	if (nb > (t_lu)base - 1)
		counter += ft_putul(nb / base, str, base, counter);
	counter += write(1, &str[nb % base], 1);
	return (counter);
}
