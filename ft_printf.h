/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:26:53 by wmika             #+#    #+#             */
/*   Updated: 2021/10/22 14:27:00 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>

size_t	ft_strlen(const char *str);
int		printf_p(void *ptr, char c);
int		ft_putnbr_base(unsigned long long nbr, char *base, char c);
int		check(char *base);
void	ft_putstr(char *str, char c);
int		count_base(char *base);
int		printf_str(char *str);
int		printf_char(int c);
int		ft_printf(const char *p, ...);
int		printf_d(int n);
char	*ft_itoa(int n);
int		length_str(int n);
int		ft_putnbr_base_1( unsigned int nbr, char *base, char c);
int		printf_x(void *ptr, char c);
int		length_str_u(unsigned int n);
char	*ft_itoa_u(unsigned int n);
int		printf_u( unsigned int n);
int		get_res(const char *p, int i, va_list cp, int res);

#endif
