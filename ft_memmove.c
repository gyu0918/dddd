/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:04:01 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/23 17:43:08 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	if (dst == src || len == 0)
		return (dst);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (src < dst)
	{	
		while (i < len)
		{
			tmp_dst[len - i -1] = tmp_src[len - i -1];
			i++;
		}
	}
	else
		ft_memcpy((void *)tmp_dst, (const void *)tmp_src, len);
	return (dst);
}
