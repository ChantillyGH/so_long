/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:30:05 by mdoroana          #+#    #+#             */
/*   Updated: 2022/03/02 18:44:54 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nstrings(char const *s, char c)
{
	int	i;
	int	ns;

	i = 0;
	ns = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			ns++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (ns);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**new;
	size_t	ns;

	if (s == NULL)
		return (NULL);
	ns = ft_nstrings(s, c);
	new = (char **)malloc(sizeof(char *) * (ns + 1));
	if (new == NULL)
		return (NULL);
	str = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (str != s)
				*(new ++) = ft_substr(str, 0, s - str);
			str = (char *)s + 1;
		}
		s++;
	}
	if (str != s)
		*(new ++) = ft_substr(str, 0, s - str);
	*new = 0;
	return (new - ns);
}
