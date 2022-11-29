/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyjo <kyjo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:02:09 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/23 17:25:41 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cc;

	cc = (unsigned char)c;
	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = cc;
		i++;
	}
	return ((void *)b);
}
