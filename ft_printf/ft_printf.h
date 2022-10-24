/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:18:39 by mdoroana          #+#    #+#             */
/*   Updated: 2022/03/29 17:26:04 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define DEC	"0123456789"
# define HEXS	"0123456789abcdef"
# define HEXL	"0123456789ABCDEF"

# include<stdarg.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

typedef unsigned int	t_ui;
typedef unsigned long	t_lu;

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_writenb(int nb, int counter);
int	ft_putnbr(int nb);
int	ft_putul(t_lu nb, char *str, int base, int counter);
int	ft_printf(const char *str, ...);

#endif