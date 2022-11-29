/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:49:25 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/23 18:57:34 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_mem;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[start] && ft_strchr(set, s1[start]) && start < end)
		start++;
	while (i < end)
	{
		if (ft_strchr(set, s1[end - i - 1]) == 0)
			break ;
		i++;
	}
	end = end - i;
	if (start >= end)
		return (ft_strdup(""));
	new_mem = ft_substr(s1, start, end - start);
	return (new_mem);
}
