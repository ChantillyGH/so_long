/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:40:31 by mdoroana          #+#    #+#             */
/*   Updated: 2022/10/24 17:39:17 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *str)
{
	char	*s;

	s = ft_strrchr(str, '.');
	if (!s)
		return (1);
	if (ft_strncmp(s, ".ber", 5))
	{
		printf("Map extension is wrong");
		return (1);	
	}
	return (0);
}
