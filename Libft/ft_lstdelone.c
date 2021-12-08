/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:17:42 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/09 09:17:45 by tarchimb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"


void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*head;

	head = lst;
	del (lst->content);
	free(head);
}
