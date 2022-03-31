/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:16:25 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/17 15:12:09 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

static void	ft_recursive(int nb, int *i, char *str)
{
	if (nb == 0)
	{
		(str[*i] = 0 + '0');
		*i += 1;
		return ;
	}
	if (nb < -9 || nb > 9)
	{
		ft_recursive(nb / 10, i, str);
	}
	if (nb < 0)
	{
		str[*i] = (-(nb % 10) + '0');
		*i += 1;
	}
	else
	{
		str[*i] = nb % 10 + '0' ;
		*i += 1;
	}
}

static void	ft_putnbr(int nb, char *str, int *i)
{
	if (nb < 0)
	{
		str[0] = '-';
		*i += 1;
	}
	ft_recursive(nb, i, str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		tmp;

	str = 0;
	i = 0;
	tmp = n;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		i++;
	}
	if (n <= 0)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	ft_putnbr(n, str, &i);
	str[i] = '\0';
	return (str);
}
