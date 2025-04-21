/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:44:12 by jaeklee           #+#    #+#             */
/*   Updated: 2025/04/21 15:43:03 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	size_t	len;
	size_t	i;
	char	*tmp;

	first = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	last = len - 1;
	while (last > first && ft_strchr(set, s1[last]))
		last--;
	len = last - first + 1;
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (first <= last)
		tmp [i++] = s1 [first++];
	tmp[i] = '\0';
	return (tmp);
}
