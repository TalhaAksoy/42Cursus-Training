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
	while(str[i])
	{
		len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int ft_setprint(unsigned long number, char *set, int numset)
{
	int i = 0;
	int len = 0;
	if(number < 0)
	{
		len += write(1, "-", 1);
		number = number * -1;
	}
	if(number > numset - 1)
		len += ft_setprint(number/numset,set,numset);
	len += write(1, &set[number%numset], 1);
	return (len);
}

int arg_printer(va_list macro, char c)
{
	if(c == 's')
		return(ft_putstr(va_arg(macro, char *)));
	if(c == 'd')
		return(ft_setprint(va_arg(macro, int), "0123456789", 10));
	if(c == 'x')
		return(ft_setprint(va_arg(macro, unsigned int), "0123456789abcdef", 16));
	return (0);
}
int ft_printf(const char *str, ...)
{
	va_list macro;
	int i = 0;
	int len = 0;

	va_start(macro, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			len += arg_printer(macro, str[i + 1]);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int main()
{
	ft_printf("%x", -42);
}
