/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:27:51 by wmika             #+#    #+#             */
/*   Updated: 2021/10/22 14:27:54 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_base_1(unsigned int nbr, char *base, char c)
{
	int				i;
	char			str[32];
	unsigned int	count;
	unsigned int	num;

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

int	printf_x(void *ptr, char c)
{
	unsigned int	i;

	i = (unsigned int) ptr;
	if (c == 'x')
		return (ft_putnbr_base_1(i, "0123456789abcdef", c));
	return (ft_putnbr_base_1(i, "0123456789ABCDEF", c));
}
