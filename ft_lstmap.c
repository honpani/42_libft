/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthongka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:31:22 by pthongka          #+#    #+#             */
/*   Updated: 2022/03/27 15:33:53 by pthongka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmpnode;

	if (!lst)
		return (0);
	newlst = 0;
	while (lst)
	{
		tmpnode = ft_lstnew(f(lst->content));
		if (!tmpnode)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, tmpnode);
		lst = lst->next;
	}
	return (newlst);
}
