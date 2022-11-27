/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:44:00 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/27 19:07:46 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstr(char *s, int *len)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		(*len) += 1;
	}
}
