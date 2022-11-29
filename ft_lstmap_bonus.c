/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:01:36 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/23 17:38:57 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*temp;
	t_list	*cur;

	if (lst == NULL || f == NULL)
		return (0);
	temp = NULL;
	while (lst)
	{
		cur = ft_lstnew((*f)(lst->content));
		if (!(cur))
		{
			ft_lstclear(&cur, del);
			return (NULL);
		}
		ft_lstadd_back(&temp, cur);
		lst = lst->next;
	}
	return (temp);
}
