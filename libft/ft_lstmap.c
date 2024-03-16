/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:18:31 by crepou            #+#    #+#             */
/*   Updated: 2022/11/22 15:41:32 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_listnew(void *content, void (*del)(void *))
{
	t_list	*nd;

	nd = ft_lstnew(content);
	if (!nd)
	{
		del(content);
		return (NULL);
	}
	return (nd);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*l;
	int		flag;

	if (!lst || !f || !del)
		return (NULL);
	flag = 0;
	new_lst = ft_listnew(f(lst->content), del);
	if (!new_lst)
		return (NULL);
	l = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		new_lst->next = ft_listnew(f(lst->content), del);
		if (!(new_lst)->next)
		{
			ft_lstclear(&l, del);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (l);
}
