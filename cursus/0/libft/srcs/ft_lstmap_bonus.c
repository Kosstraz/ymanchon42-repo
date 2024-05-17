/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:13:18 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 20:14:07 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;

	(void)del;
	if (!lst)
		return ((void *)0);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ((void *)0);
	ret = new;
	while (lst)
	{
		new->content = f(lst->content);	
		if (lst->next)
		{
			new->next = (t_list *)malloc(sizeof(t_list));
			if (!(new->next))
				return ((void *)0);
		}
		new = new->next;
		lst = lst->next;
	}
	return (ret);
}
