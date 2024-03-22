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
	t_list	*new_lst;
	t_list	*ret;

	if (!lst)
		return ((t_list *)0);
	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->item = f(lst->item);
	new_lst->next = (void *)0;
	lst = lst->next;
	ret = new_lst;
	while (lst)
	{
		new_lst = (t_list *)malloc(sizeof(t_list));
		if (!new_lst)
			return (NULL);
		new_lst->item = f(lst->item);
		new_lst->next = (void*)0;
		if (lst->next)
			new_lst = new_lst->next;
		lst = lst->next;
	}
	return (ret);
}
