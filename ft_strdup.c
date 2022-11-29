/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:35:18 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/18 05:29:15 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*result;
	size_t		len_s;
	size_t		i;

	result = NULL;
	i = 0;
	while (s1[i])
		i++;
	len_s = i;
	result = (char *)malloc((len_s + 1) * sizeof(char));
	if (!(result))
		return (0);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
