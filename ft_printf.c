/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:28:06 by wmika             #+#    #+#             */
/*   Updated: 2021/10/22 14:28:09 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	get_res(const char *p, int i, va_list cp, int res)
{
	if (p[i] == '%' && p[i + 1] == 'c')
		res += printf_char(va_arg(cp, int));
	if (p[i] == '%' && p[i + 1] == 's')
		res += printf_str(va_arg(cp, char *));
	if (p[i] == '%' && p[i + 1] == 'p')
		res += printf_p(va_arg(cp, void *), p[i + 1]);
	if (p[i] == '%' && p[i + 1] == 'd')
		res += printf_d(va_arg(cp, int));
	if (p[i] == '%' && p[i + 1] == 'i')
		res += printf_d(va_arg(cp, int));
	if (p[i] == '%' && p[i + 1] == 'u')
		res += printf_u(va_arg(cp, unsigned int));
	if (p[i] == '%' && (p[i + 1] == 'x' || p[i + 1] == 'X'))
		res += printf_x(va_arg(cp, void *), p[i + 1]);
	if (p[i] == '%' && p[i + 1] == '%')
		res += printf_char('%');
	return (res);
}

int	ft_printf(const char *p, ...)
{
	va_list	cp;
	int		res;
	int		i;

	i = 0;
	res = 0;
	va_start(cp, p);
	while (p[i])
	{
		if (p[i] != '%')
		{
			write(1, &p[i], 1);
			res++;
			i++;
		}
		else
		{	
			res = get_res(p, i, cp, res);
			i = i + 2;
		}
	}
	va_end(cp);
	return (res);
}
