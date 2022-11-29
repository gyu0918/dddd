/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:03:55 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/23 17:39:10 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlst;

	newlst = NULL;
	newlst = malloc(sizeof(t_list));
	if (!(newlst))
		return (NULL);
	newlst->content = content;
	newlst->next = NULL;
	return (newlst);
}
