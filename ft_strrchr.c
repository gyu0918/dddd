/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:26 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/18 07:27:28 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	cc;
	size_t	i;

	result = (char *)s;
	cc = (char)c;
	i = ft_strlen(s);
	if (cc == '\0')
		return (&result[i]);
	while (i > 0)
	{
		if (result[i] == cc)
			return (&result[i]);
		i--;
	}
	if (result[i] == cc)
		return (&result[i]);
	return (NULL);
}
