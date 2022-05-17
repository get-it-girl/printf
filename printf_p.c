/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:29:14 by wmika             #+#    #+#             */
/*   Updated: 2021/10/22 14:29:15 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	count_base(char *base)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (base[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

void	ft_putstr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (c == 'p')
		write (1, "0x", 2);
	i--;
	while (i >= 0)
	{
		write (1, &str[i], 1);
		i--;
	}
}

int	check(char *base)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = base;
	if (count_base(base) == 0 || count_base(base) == 1)
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = 0;
		while (j <= count_base(base))
		{
			if (base[i] == str[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_putnbr_base(unsigned long long nbr, char *base, char c)
{
	int					i;
	char				str[32];
	unsigned long long	count;
	unsigned long long	num;

	i = 0;
	num = nbr;
	count = count_base(base);
	if (num < 0)
		num = num * (-1);
	while (num >= count)
	{
		str[i] = base[num % count];
		num = num / count;
		i++;
	}
	str[i] = base[num];
	str[i + 1] = '\0';
	ft_putstr(str, c);
	return (ft_strlen(str));
}

int	printf_p(void *ptr, char c)
{
	unsigned long long	i;

	i = (unsigned long long) ptr;
	return (ft_putnbr_base(i, "0123456789abcdef", c) + 2);
}
