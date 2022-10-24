/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:40:31 by mdoroana          #+#    #+#             */
/*   Updated: 2022/10/21 21:47:34 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *str)
{
	ft_strrchr(str, 5);
	if (!ft_strncmp(str, ".ber", 5))
		printf("Map extension is wrong");
	return (0);
}
