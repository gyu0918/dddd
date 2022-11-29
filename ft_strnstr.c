/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:48:51 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/23 18:37:43 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)haystack;
	i = 0;
	if (ft_strlen(needle) == 0)
		return (tmp);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while (i < len)
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
		{
			if (len < ft_strlen(needle) + i)
				return (NULL);
			return (tmp);
		}
		tmp++;
		i++;
	}
	return (NULL);
}
