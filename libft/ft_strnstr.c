/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:38:49 by mdoroana          #+#    #+#             */
/*   Updated: 2022/02/16 17:15:58 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h] != '\0' && h < len)
	{
		n = 0;
		while (haystack[h + n] && needle[n] && h + n < len
			&& haystack[h + n] == needle[n])
			n++;
		if (!needle[n])
			return ((char *)(haystack + h));
		h++;
	}
	return (NULL);
}
