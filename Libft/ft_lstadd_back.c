/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:51:30 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/09 14:39:16 by tarchimb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"


void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!new->next)
		new->next = NULL;
	if (!*alst)
		*alst = new;
	else
	{
		last = *alst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
