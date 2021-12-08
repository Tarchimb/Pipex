/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:03:23 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/10 09:46:46 by tarchimb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "../Includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*csrc;
	char	*cdst;

	if (!dst && !src)
		return (0);
	csrc = (char *)src;
	cdst = (char *)dst;
	i = 0;
	while (n > 0)
	{
		cdst[i] = csrc[i];
		i++;
		n--;
	}
	return (dst);
}
