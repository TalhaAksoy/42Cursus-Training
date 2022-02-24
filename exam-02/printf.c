/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:09:39 by saksoy            #+#    #+#             */
/*   Updated: 2022/02/24 14:30:52 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_putstr(char *str)
{
	int i = 0;
	int len = 0;
	while (str[i] && str)
	{
		len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int ft_putchar(char c)
{
	int sayi;

	sayi = 0;
	sayi += write(1, &c, 1);
	return (sayi);
}

int ft_putnbr(int number, char *set, int numset)
{
	int len;

	len = 0;
	if (number == -2147483648)
		len += ft_putstr("-2147483648");
	if (number < 0)
	{
		number = number * -1;
		ft_putchar('-');
		len++;
	}
	if(number > numset - 1)
		len += ft_putnbr(number/numset , set, numset);
	len += ft_putchar(set[number%numset]);
	
	return(len);
}

int	arg_printer(va_list macro, char c)
{
	if(c == 's')
		return(ft_putstr(va_arg(macro, char *)));
	if(c == 'd')
		return(ft_putnbr(va_arg(macro, int), "0123456789", 10));
	if(c == 'x')
		return(ft_putnbr(va_arg(macro, unsigned int), "0123456789abcdef", 16));
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list macro;
	int i;
	int len;

	va_start(macro, str);
	len = 0;
	i = 0;
	while(str[i])
	{
		if(str[i] == '%')
		{
			len += arg_printer(macro, str[i+1]);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(macro);
	return (len);
}

int main(void)
{
	ft_printf("%x\n", 42);
}