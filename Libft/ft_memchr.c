/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:36:09 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/04 08:11:32 by tarchimb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0 || s == 0)
	{
		if (*(unsigned char *)s == (unsigned char) c)
			return ((unsigned char *)s);
		n--;
		s++;
	}
	return (NULL);
}
