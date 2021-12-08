/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:26:17 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/10 07:55:47 by tarchimb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = 0;
	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) >= len)
		i = len;
	else
		i = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (len > 0 && s[start])
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = '\0';
	return (str);
}
