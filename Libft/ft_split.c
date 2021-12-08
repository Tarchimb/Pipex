/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:52:57 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/11 09:34:57 by tarchimb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

static int	ft_count_c(char c, const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || !s[i])
			{
				j++;
			}
		}
		if (s[i])
			i++;
	}
	if (j == 0)
		return (2);
	return (j + 1);
}

static int	ft_check_c(char c, char s)
{
	if (c == s)
		return (1);
	return (0);
}

static char	*ft_strdupp(char const *s, char c, int *i)
{
	char	*str;
	int		size;
	int		j;

	str = 0;
	size = 0;
	j = 0;
	while (ft_check_c(s[*i], c) == 0 && s[*i])
	{
		size++;
		*i += 1;
	}
	str = (char *)malloc(sizeof(char) * (size + 2));
	if (!str)
		return (ft_calloc(1, 0));
	*i = *i - size;
	while (ft_check_c(s[*i], c) == 0 && s[*i])
	{
		str[j] = s[*i];
		*i += 1;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static void	*ft_check_null(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * ft_count_c(c, s));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (ft_check_c(c, s[i]) == 0)
		{
			str[j] = ft_strdupp(s, c, &i);
			if (!str[j])
				return (ft_check_null(str));
			j++;
		}
		else
			i++;
	}
	str[j] = 0;
	return (str);
}
